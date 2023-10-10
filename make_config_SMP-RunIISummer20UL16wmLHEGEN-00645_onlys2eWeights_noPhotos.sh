#! /bin/bash

fragment=SMP-RunIISummer20UL16wmLHEGEN-00645_onlys2wWeights_noPhotos_cff.py
outputfile=SMP-RunIISummer20UL16wmLHEGEN-00645_onlys2wWeights_noPhotos.root

customize="--customise_commands process.RandomNumberGeneratorService.externalLHEProducer.initialSeed=999"
#customize="${customize}\nprocess.externalLHEProducer.generateConcurrently=True --nThreads 8"

cmsenv
cmsDriver.py Configuration/SMP-22-010_NanoGen/python/$fragment \
    --fileout file:$outputfile --mc --eventcontent NANOAODSIM \
    --datatier NANOAOD --conditions auto:mc --step LHE,GEN,NANOGEN \
    --python_filename configs/${fragment/cff/cfg} \
    $customize \
    -n 10 --no_exec
