build_protobuf(){
  cd $SRC
  ./autogen.sh
  ./configure --prefix=$DST
  make -j$(nproc)
  make check
  make install
}

