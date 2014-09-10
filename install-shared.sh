#!/bin/bash -x
DIR=/usr/lib
SLIB=liblpaggreg.so
cd Shared
LSLIB=`ls ${SLIB}*`
cd ..
rm $DIR/$SLIB
cp Release/$LSLIB $DIR
ln -s $DIR/$LSLIB $DIR/$SLIB
mkdir -p /usr/include/lpaggreg
cp src/*.h /usr/include/lpaggreg
echo "/usr/lib/" > /etc/ld.so.conf.d/lpaggreg.conf
ldconfig
exit 0
