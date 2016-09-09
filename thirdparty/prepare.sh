#! /bin/sh
#
# prepare.sh
# Copyright (C) 2016 lisanmiao <lisanmiao@cp01-rdqa-dev367.cp01.baidu.com>
#
# Distributed under terms of the MIT license.
#


#prepare boost
wget http://nchc.dl.sourceforge.net/project/boost/boost/1.61.0/boost_1_61_0.tar.gz .
tar -zxvf boost_1_61_0.tar.gz
pushd boost_1_61_0
sh bootstrap.sh --with-libraries=log
./b2
popd
