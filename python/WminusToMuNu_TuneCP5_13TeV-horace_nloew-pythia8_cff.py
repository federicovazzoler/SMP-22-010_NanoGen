import FWCore.ParameterSet.Config as cms

externalLHEProducer = cms.EDProducer("ExternalLHEProducer",
    args = cms.vstring('/afs/cern.ch/work/m/mseidel/public/MiNNLO-gridpacks/slc6_amd64_gcc700_CMSSW_10_2_29_WminusToMuNu-13TeV-nnpdf31-horace-exp-new.tar.gz'),
    generateConcurrently = cms.untracked.bool(True),
    nEvents = cms.untracked.uint32(10000),
    numberOfParameters = cms.uint32(1),
    outputFile = cms.string('cmsgrid_final.lhe'),
    scriptName = cms.FileInPath('GeneratorInterface/LHEInterface/data/run_generic_tarball_cvmfs.sh')
)

import FWCore.ParameterSet.Config as cms

from Configuration.Generator.Pythia8CommonSettings_cfi import *
from Configuration.Generator.MCTunes2017.PythiaCP5Settings_cfi import *
from Configuration.Generator.PSweightsPythia.PythiaPSweightsSettings_cfi import *

# NOTE: HORACE NLO EW includes ISR QED emissions -> turned off in Pythia

generator = cms.EDFilter("Pythia8HadronizerFilter",
    maxEventsToPrint = cms.untracked.int32(1),
    pythiaPylistVerbosity = cms.untracked.int32(1),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    comEnergy = cms.double(13000.),
    PythiaParameters = cms.PSet(
        pythia8CommonSettingsBlock,
        pythia8CP5SettingsBlock,
        pythia8PSweightsSettingsBlock,
        processParameters = cms.vstring(
            'SpaceShower:pTmaxMatch = 1', # no emissions with pt>scalup as in already-produced Horace samples, should ideally be 0 (up to kinematic limit) for LO QCD samples
            'TimeShower:pTmaxMatch = 1',
            'ParticleDecays:allowPhotonRadiation = on',
            'TimeShower:QEDshowerByL = off',
            'TimeShower:QEDshowerByOther = off',
            'BeamRemnants:hardKTOnlyLHE = on',
            'BeamRemnants:primordialKThard = 2.225001',
            'SpaceShower:dipoleRecoil = 1',
            'SpaceShower:QEDshowerByQ = off',
            'SpaceShower:QEDshowerByL = off'
        ),
		parameterSets = cms.vstring('pythia8CommonSettings',
                                    'pythia8CP5Settings',
                                    #'pythia8PSweightsSettings',
                                    'processParameters')
    ),
)

ProductionFilterSequence = cms.Sequence(generator)
