#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.us.z64'
    config['myimg'] = 'build/marioparty2.z64'
    config['mapfile'] = 'build/marioparty2.map'
    config['source_directories'] = ['.']
    config['makeflags'] = ['COMPARE=0']