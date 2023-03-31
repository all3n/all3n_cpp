boost_url(){
  local REVISION=$1
  local REV_UNDERLINE=$(echo $REVISION|sed -e "s/\./_/g")
  echo "https://boostorg.jfrog.io/artifactory/main/release/${REVISION}/source/boost_${REV_UNDERLINE}.tar.gz"
}
build_boost(){
  BUILD_DIR=$DEP_DIR/build/$repo/$REVISION
  cd $SRC
  ./bootstrap.sh --prefix=$DST --with-libraries=$modules
  #./b2 --build-dir=$BUILD_DIR --prefix=$DST
  ./b2 install
  #./autogen.sh
  #./configure --prefix=$DST
  #make -j$(nproc)
  #make check
  #make install
}

