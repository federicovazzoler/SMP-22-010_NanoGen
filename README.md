# Setup to run NanoGen and store LHE weights
```
CMSSWver=CMSSW_13_0_0
cmsrel ${CMSSWver}
cd ${CMSSWver}/src
cmsenv
git cms-init
scram b -j `nproc`
mkdir -p Configuration
cd Configuration
git clone git@github.com:federicovazzoler/SMP-22-010_NanoGen.git
scram b -j `nproc`

```

# Making configs and running

1. Create a config fragment in python/<your config>. Follow the other examples there.
2. Run [make_config.sh](make_config.sh). Example `./make_config.sh python/<your config>` will create the appropriate config file under `configs`.
3. Run the config file by using [run_config.sh](run_config.sh). Example `./run_config.sh configs/<your config>`.

Example crab submit files are in the crab_submit_files directory. Note that you need to copy the gridpacks to a location readable from crab for this to work.

# Commands used for SMP-22-010

To make the configs:
```
./make_config.sh python/ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-adds2wvars_cff.py 1000
./make_config.sh python/ZJToEE-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-adds2wvars_cff.py 1000
./make_config.sh python/ZJToTauTau-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-adds2wvars_cff.py 1000

```

The `configs/ZJToEE_CT18variations_singleJob_final.py` are the final working configs for the PDF variations
