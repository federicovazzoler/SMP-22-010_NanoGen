#!/usr/bin/env python3
"""
This is a small script that does the equivalent of multicrab.
"""
import os
from optparse import OptionParser

from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException

def getOptions():
    """
    Parse and return the arguments provided by the user.
    """
    usage = ("Usage: %prog --crabCmd CMD [--workArea WAD --crabCmdOpts OPTS]"
             "\nThe multicrab command executes 'crab CMD OPTS' for each project directory contained in WAD"
             "\nUse multicrab -h for help")

    parser = OptionParser(usage=usage)

    parser.add_option('-c', '--crabCmd',
                      dest = 'crabCmd',
                      default = '',
                      help = "crab command",
                      metavar = 'CMD')

    parser.add_option('-w', '--workArea',
                      dest = 'workArea',
                      default = '',
                      help = "work area directory (only if CMD != 'submit')",
                      metavar = 'WAD')

    parser.add_option('-o', '--crabCmdOpts',
                      dest = 'crabCmdOpts',
                      default = '',
                      help = "options for crab command CMD",
                      metavar = 'OPTS')

    parser.add_option('-T', '--Type',
                      dest = 'Type',
                      default = '',
                      help = "Data or MC",
                      metavar = 'OPTS')

    parser.add_option('-W', '--weight',
                      dest = 'weight',
                      type=int,
                      default = -1,
                      help = "level of weights",
                      metavar = 'OPTS')

    parser.add_option('-S', '--step',
                      dest = 'step',
                      type=int,
                      default = -1,
                      help = "step of the powheg.sh script",
                      metavar = 'OPTS')

    (options, arguments) = parser.parse_args()

    if arguments:
        parser.error("Found positional argument(s): %s." % (arguments))
    if not options.crabCmd:
        parser.error("(-c CMD, --crabCmd=CMD) option not provided.")
    if options.crabCmd != 'submit':
        if not options.workArea:
            parser.error("(-w WAR, --workArea=WAR) option not provided.")
        if not os.path.isdir(options.workArea):
            parser.error("'%s' is not a valid directory." % (options.workArea))

    else:
        if not options.Type: parser.error("--type option not provided.")
        if options.weight<0: parser.error("--weight option not provided.")
        if options.step<0: parser.error("--step option not provided.")

    return options

testRun=False

def main():

    options = getOptions()

    name = options.Type

    if options.crabCmd == 'submit':
        from CRABClient.UserUtilities import config
        config = config()

        config.General.requestName = name
        config.General.workArea = "v11crab"
        config.General.transferOutputs = True
        config.General.transferLogs = False

        config.Site.storageSite	= 'T2_CH_CERN'
        config.Site.blacklist = ['T1_UK_RAL', 'T2_IT_Rome', 'T2_IT_Pisa', 'T2_UK_London_IC', 'T2_RU_INR', 'T3_KR_KNU']

        config.Data.publication	= False
        config.Data.outputPrimaryDataset = 'Powheg'
        config.Data.totalUnits = 100000000
        config.Data.unitsPerJob	= 10000
        if options.weight < 2:
            config.Data.unitsPerJob = 250000
            config.Data.totalUnits  = 2500000000
        config.Data.splitting = 'EventBased'
        config.Data.outLFNDirBase = '/store/group/phys_smp/sin2O'

        config.JobType.pluginName = 'PrivateMC'
        config.JobType.scriptExe = 'powheg.sh'
        config.JobType.outputFiles = ['ntuple.root']
        config.JobType.psetName	= 'base/dummy.py'
        config.JobType.inputFiles = ['package/{0}.tar.gz'.format(name)]
        config.JobType.eventsPerLumi = 1000

        if testRun:
            config.Data.totalUnits = 2000
            config.Data.unitsPerJob = 100

        if options.step==10:
            config.Data.totalUnits = 201
            config.Data.unitsPerJob = 1
            config.JobType.outputFiles = ['{0}.tar.gz'.format(name)]

        config.JobType.scriptArgs = ['step={0}'.format(options.step),
                                     'pkgdir=.',
                                     'workdir=.',
                                     'version={0}'.format(name),
                                     'numevts={0}'.format(config.Data.unitsPerJob),
                                     'weight={0}'.format(options.weight)]

        crabCommand(options.crabCmd, config = config, *options.crabCmdOpts.split())


    elif options.workArea:

        for dir in os.listdir(options.workArea):
            projDir = os.path.join(options.workArea, dir)
            if not os.path.isdir(projDir): continue
            # Execute the crab command.
            msg = "Executing (the equivalent of): crab %s --dir %s %s" % (options.crabCmd, projDir, options.crabCmdOpts)
            print("-"*len(msg))
            print(msg)
            print("-"*len(msg))
            crabCommand(options.crabCmd, dir = projDir, *options.crabCmdOpts.split())

if __name__ == '__main__':
    main()


