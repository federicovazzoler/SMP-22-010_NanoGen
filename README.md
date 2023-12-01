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
