A plotter code(for plotting from Ntuples) is being developed for HLLHC jet substructure studies. The work is still in progress. The code is useful to plot any number of any variables from ntuples quickly. Only the user have to change things in the InputDetails.dat and press the botton. The python scripts will create the relevent c++ codes that could be run get the required histograms stored in a tree.  

Step0. Execute the following command to copy the code to your area
```
git clone https://github.com/bmahakud/PlotterHLLHCSubstructure
```

Step1. Edit the InputDetails.dat file according to your need. here one has to put the input file locations , variables to be plotted, different categories if there. 

Step2. Execute the following command to create the following c++ codes that will be used to run on Ntuples. The files that will be created are ClassReadSig.cc, ClassReadBkg.cc, ClassReadData.cc, HistCreater.C, Loader.C, Looper_sig.C, Looper_bkg.C, Looper_data.C, Analyzer.C


```
./Setup
```

Step3.
```
root -l Analyzer.C
```

You can define various histograms inside Analyzer.C and do your analysis

