import uproot
import numpy as np
import awkward as ak
import matplotlib.pyplot as plt
import mplhep as hep
import scipy
from scipy.optimize import curve_fit
from scipy.stats import norm

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
    print("Gaussian fitting covariance:",pcov)
    A = popt[0]
    mu = popt[1]
    sigma = popt[2]
    return hist_plx, A, mu, sigma

## define main function
def process(file):
    # read file
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
    plt.figure(figsize=(8, 8))
    histo = plt.hist(ADC1,
        bins=60, range=(600, 900), color='blue',
        histtype='step', label='ADC1', linewidth=2)
    plt.tick_params(axis='y', labelsize=15)
    plt.xlim(600, 900)

    # Y-axis is log scale
    plt.yscale('log')

    # Set title
    plt.xlabel('ADC [count]')
    plt.ylabel('Number of entries')

    # Gaussian fitting the histogram -- pedestal region
    hist_plx, A, mu, sigma = fitFunction(histo,645,690)

    # Gaussian fitting plot
    plt.plot(hist_plx, gaussian(hist_plx, A, mu, sigma),
        color='red', label='fit: a=%5.2f, b=%5.2f, c=%5.2f' % tuple([A,mu,sigma]), linewidth=2)
    
    # Gaussian fitting the histogram -- signal region
    hist_plx, A, mu, sigma = fitFunction(histo,740,840)

    # Gaussian fitting plot
    print(A,mu,sigma)
    plt.plot(hist_plx, gaussian(hist_plx, A, mu, sigma),
        color='green', label='fit: a=%5.2f, b=%5.2f, c=%5.2f' % tuple([A,mu,sigma]), linewidth=2)

    # set legend
    plt.legend(fontsize=15)
    
    # save figure
    plt.savefig('ADC1.png')

    return 0

# File name
file = '/x6/spool/twkim/Desktop/Class/HV_1700V.root'

# Direct launch
if __name__ == '__main__':
    process(file)