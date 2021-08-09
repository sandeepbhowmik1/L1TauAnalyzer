# L1TauAnalyzer

# The main package is copied from 

```
https://github.com/davignon/TauTagAndProbe
```

#  Environment setup

Setup the environment according to the [official instructions](https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideL1TStage2Instructions)

```
cmsrel CMSSW_11_2_0
cd CMSSW_11_2_0/src
cmsenv
git cms-init
#git remote add cms-l1t-offline git@github.com:cms-l1t-offline/cmssw.git
git remote add cms-l1t-offline https://github.com/cms-l1t-offline/cmssw
git fetch cms-l1t-offline l1t-integration-CMSSW_11_2_0
git cms-merge-topic -u cms-l1t-offline:l1t-integration-v105.20.1
git cms-addpkg L1Trigger/Configuration
git cms-addpkg L1Trigger/L1TMuon
git clone https://github.com/cms-l1t-offline/L1Trigger-L1TMuon.git L1Trigger/L1TMuon/data
git cms-addpkg L1Trigger/L1TCalorimeter
git clone https://github.com/cms-l1t-offline/L1Trigger-L1TCalorimeter.git L1Trigger/L1TCalorimeter/data
git cms-checkdeps -A -a
scram b -j 8
```


# Download the L1TauAnalyzer/L1TauAnalyzer code

Clone this repository into your `$CMSSW_BASE/src/` folder.

```
git clone https://github.com/sandeepbhowmik1/L1TauAnalyzer
```
