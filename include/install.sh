#!/bin/sh
PREFIX="/usr"
includes="$(cat includes_list)"

main()
{
	for i in $includes; do
		install -v -Dm 644 -o root -g root $i $DESTDIR$PREFIX/include/$i;
	done
}

main
