#!/usr/bin/env python3

import uproot
import numpy as np
import awkward as ak
import matplotlib.pyplot as plt
import mplhep as hep
import scipy
from scipy.optimize import curve_fit
from scipy.stats import norm
import multiprocessing

## Gaussian Function
def gaussian(x, a, x0, sigma):
    return a*np.exp(-(x-x0)**2/(2*sigma**2))

def fitFunction(histo,minx,maxx):
    # Gaussian fitting the histogram
    hist_N = histo[0]
    hist_bin = histo[1]
    hist_bin_center = (hist_bin[:-1] + hist_bin[1:])/2
    fit_range = (hist_bin_center > minx) & (hist_bin_center < maxx)
    hist_plx = hist_bin_center[fit_range]
    hist_ply = hist_N[fit_range]
    sigma, mu = np.std(hist_plx), np.mean(hist_plx)

    # Gaussian fitting
    popt, pcov = curve_fit(gaussian, hist_plx, hist_ply, p0=[1, mu, sigma])
    print("Gaussian fitting parameters:",popt)
    #print("Gaussian fitting covariance:",pcov)
    A = popt[0]
    mu = popt[1]
    sigma = popt[2]
    return hist_plx, A, mu, sigma

## define main function
def process(volt):
    # read file
    file = '/x6/spool/twkim/Desktop/Class/0412/HV_'+str(volt)+'V.root'
    f = uproot.open(file)
    print("Trees:",f.keys())

    # read tree
    tr = f['tr']
    print("Branches:",tr.keys())

    # read adc1 branches
    for key in tr.keys():
        if key == 'adc1':
            ADC1 = tr[key].array()
            print("Branch|adc1:",ADC1)
            print("Entry:",len(ADC1))
            for i in range(20):
                print("Entry:",i,"adc1:",ADC1[i])
    

    # draw histogram
    plt.style.use(hep.style.CMS)
    plt.figure(figsize=(16, 8))

    plt.subplot(1, 2, 1)
    plt.subplots_adjust(wspace=0.35)
    histo = plt.hist(ADC1,
        bins=60, range=(600, 900), color='blue',
        histtype='step', label='ADC1', linewidth=2)
    plt.tick_params(axis='y', labelsize=15)
    plt.xlim(600, 900)

    # ADC peak position
    sig = 10+ (volt-1400)/100*10
    print(sig)
    xmin = 700 - sig + (volt-1400)/100*30
    xmax = 700 + sig + (volt-1400)/100*30
    print(xmin,xmax)

    # Gaussian fitting the histogram -- pedestal region
    hist_plx, A, mu, sigma = fitFunction(histo,645,690)
    # Gaussian fitting plot
    plt.plot(np.linspace(mu-sigma,mu+sigma), gaussian(np.linspace(mu-sigma,mu+sigma), A, mu, sigma),
        color='red', label='fit: mean=%5.2f, std=%5.2f' % tuple([mu,sigma]), linewidth=2)

    # Fit parameters > txt file
    with open('ADC_'+str(volt)+'.txt', 'w') as f:
        f.write(str(volt)+' '+str(mu)+' '+str(abs(sigma)))

    # Gaussian fitting the histogram -- signal region
    hist_plx, A, mu, sigma = fitFunction(histo,xmin,xmax)

    with open('ADC_'+str(volt)+'.txt', 'a') as f:
        f.write(str(volt)+' '+str(mu)+' '+str(abs(sigma))+'\n')

    # Gaussian fitting plot
    plt.plot(np.linspace(xmin,xmax), gaussian(np.linspace(xmin,xmax), A, mu, sigma),
        color='cyan', label='fit: mean=%5.2f, std=%5.2f' % tuple([mu,sigma]), linewidth=2)

    # Y-axis is log scale
    plt.yscale('log')

    # Set title
    plt.xlabel('ADC [count]')
    plt.ylabel('Number of entries')
    plt.legend(fontsize=15)

    # Divide the plot
    plt.subplot(1, 2, 2)
    histo = plt.hist(ADC1,
        bins=60, range=(600, 900), color='blue',
        histtype='step', label='ADC1', linewidth=2)
    plt.tick_params(axis='y', labelsize=15)
    plt.xlim(600, 900)

    # Set title
    plt.xlabel('ADC [count]')
    plt.ylabel('Number of entries')
    
    # Gaussian fitting plot
    hist_plx, A, mu, sigma = fitFunction(histo,645,690)
    plt.plot(np.linspace(mu-sigma,mu+sigma), gaussian(np.linspace(mu-sigma,mu+sigma), A, mu, sigma),
        color='red', label='fit: mean=%5.2f, std=%5.2f' % tuple([mu,sigma]), linewidth=2)

        # Gaussian fitting the histogram -- signal region
    hist_plx, A, mu, sigma = fitFunction(histo,xmin,xmax)

    # Gaussian fitting plot
    plt.plot(np.linspace(xmin,xmax), gaussian(np.linspace(xmin,xmax), A, mu, sigma),
        color='cyan', label='fit: mean=%5.2f, std=%5.2f' % tuple([mu,sigma]), linewidth=2)

    # set legend
    plt.legend(fontsize=15)
    
    # save figure
    plt.savefig('ADC_'+str(volt)+'.png')

    return 0

# File name
#file = '/x6/spool/twkim/Desktop/Class/HV_1700V.root'
target = [1400,1500,1600,1700,1800]
# Direct launch
if __name__ == '__main__':
    ## Multi CPU processing
    for t in target:
        pool = multiprocessing.Pool(processes=4)
        pool.map(process, [t])
        pool.close()
        pool.join()