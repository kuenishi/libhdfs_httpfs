#! /usr/bin/env python
# encoding: utf-8

VERSION="0.0.0"
APPNAME='libhdfs_httpfs'

top = '.'
out = 'build'

def options(opt):
	opt.load('compiler_cxx')

def configure(conf):
	conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
	conf.load('compiler_cxx')

	conf.check_cfg(package = 'pficommon', args = '--cflags --libs')


def build(bld):
	bld.shlib(
		source = 'hdfs_httpfs.cpp',
		target = 'hdfs_httpfs',
		use = 'PFICOMMON')
