import FWCore.ParameterSet.Config as cms
process = cms.Process("DUMMY")
process.source = cms.Source("EmptySource")                            
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000
process.p = cms.Path()
