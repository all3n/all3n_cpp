export PROJECT=ac
export HOOKS_DIR=$AC_HOME/bin/hooks.d
export PROJECT_DESC=$(cat << EOF
 ${PROJECT} is utility tool for cpp
EOF
)
if [[ "$DEBUG" == "true" ]];then
  set -x
fi



export BUILD_DIR=$AC_HOME/build
export BIN=$BUILD_DIR/merak
export DEP_DIR=$AC_HOME/deps
export DEP_PKG_DIR=$DEP_DIR/pkg
export DEP_SRC_DIR=$DEP_DIR/src
export DEP_INSTALL_DIR=$DEP_DIR/install
export AC_INSTALL=$HOME/opt/ac

. $AC_HOME/bin/functions.sh

for ACTION_SH in $(ls $AC_HOME/bin/action.d/*.sh|sort);do
  . $ACTION_SH
done

# this option only use dev mode
if [[ -f $AC_HOME/dev.env.sh ]];then
   source $AC_HOME/dev.env.sh
fi

if [[ -n $CUR_DIR ]];then
  if [[ "$AC_HOME" != "$CUR_DIR" ]];then
    if [[ -f $CUR_DIR/bin/conf.sh ]];then
       source $CUR_DIR/bin/conf.sh
    fi
  fi
fi
