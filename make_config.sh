#! /bin/bash

fragment=$(basename ${1})
outputfile=${fragment/.py/.root}
nevts=${2:-10}

customize="--customise_commands process.RandomNumberGeneratorService.externalLHEProducer.initialSeed=999"

cmsenv
cmsDriver.py Configuration/SMP-22-010_NanoGen/python/${fragment} \
    --fileout file:$outputfile --mc --eventcontent NANOAODSIM \
    --datatier NANOAOD --conditions auto:mc --step LHE,GEN,NANOGEN \
    --python_filename configs/${fragment/cff/cfg} \
    $customize \
    -n ${nevts} --no_exec
