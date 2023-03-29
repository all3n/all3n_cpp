start_gen_compile_flags(){
  cd $CUR_DIR
  COMPILE_FLAGS_FILE=$CUR_DIR/compile_flags.txt
  echo "-xc++" > $COMPILE_FLAGS_FILE
  INCLUDES=$(find $DEP_INSTALL_DIR -name include -type d)
  for INC in ${INCLUDES[@]};do
    echo "-I" >> $COMPILE_FLAGS_FILE
    echo "$INC" >> $COMPILE_FLAGS_FILE
  done
}
