#! /usr/bin/env python
# encoding: utf-8

VERSION="0.0.0"
APPNAME='libhdfs_httpfs'

top = '.'
out = 'build'
subdirs = 'hdfs_httpfs'

def options(opt):
	opt.load('compiler_cxx')
	opt.recurse(subdirs)

def configure(conf):
	conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
	conf.load('compiler_cxx')

	conf.check_cfg(package = 'pficommon', args = '--cflags --libs')
	conf.recurse(subdirs)

def build(bld):
	bld.program(
		source = 'hdfs_httpfs_test.cpp',
		target = 'hdfs_httpfs_test',
		use = 'hdfs_httpfs'
		)
	bld.recurse(subdirs)
