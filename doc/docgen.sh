#/bin/bash
# To generate all the doc from this file you need:
#
# dot
# asciidoc

echo "generating doc..."
echo
echo -e "generating arch.svg ...\c "
if dot -Tsvg arch.dot -o arch.svg; then
	echo done!
else
	echo error!
fi

for doctxt in `find .. -name "*.txt"`; do
	echo -e "generating html ${doctxt} ...\c "
	if asciidoc ${doctxt}; then
		echo done!
	else
		echo error!
	fi
done
