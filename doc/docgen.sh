#/bin/bash
echo -e "generating arch.svg ... \c"
dot -Tsvg arch.dot -o arch.svg
if [ $$ == 0 ]; then
	echo error!
else
	echo done!
fi
