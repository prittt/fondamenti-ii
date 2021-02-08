#!/bin/bash
echo 'Setting up the script...'

# Get the current gh-pages branch
mkdir gh-pages

# Load the list of things to be documented from conf.txt
doxyfiles=$(<scripts/conf.txt)

################################################################################
##### Generate the Doxygen documentation (from master) and log the output. #####
echo 'Generating Doxygen code documentation...'

for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"
	
	cwd=$(pwd)

	# Redirect both stderr and stdout to the log file and the console.
	cd $i/doxygen
	doxygen 2>&1 | tee doxygen.log
	cd $cwd

	################################################################################
	##### Copy generated doc from master folder to gh-pages one.               #####
	dir=gh-pages/$i/html
	if [ -d "$dir" ]; then rm -Rf $dir; fi
	mkdir -p $dir
	mv $i/doxygen/html gh-pages/$i

	################################################################################
	##### Creation of the zip file for the download.                           #####
	cd $i
	headers=`ls *.h`
	sources=`ls *.c`

	zip_name="${i//\//_}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done