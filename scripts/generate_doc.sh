#!/bin/bash
echo 'Setting up the script...'

# Get the current gh-pages branch
mkdir gh-pages
echo $(pwd)

# Load the list of things to be documented: data structure + elemtype
doxyfiles=$(cat scripts/conf_complete.txt)
echo '******'
echo $doxyfiles
echo '******'

################################################################################
##### Generate the Doxygen documentation (from master) and log the output. #####
echo 'Generating Doxygen code documentation...'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Let's copy the required source and header files for generating the current doc
	echo "cp $i/../*.* $i"
	cp $i/../*.* $i
	type_name=$(basename $i)
	echo "cp elemtype/$type_name/*.* $i"
	cp elemtype/$type_name/*.* $i

	# Redirect both stderr and stdout to the log file and the console.
	cd $i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
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
	headers=$(ls -I homepage.h | egrep '*.h$')
	sources=$(ls *.c)

	zip_name="${i//\//_}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done

# Load the list of things to be documented: only data structures
doxyfiles=$(cat scripts/conf_datastruct.txt)
echo '******'
echo $doxyfiles
echo '******'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Redirect both stderr and stdout to the log file and the console.
	cd $i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
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
	headers=$(ls *.h)
	sources=$(ls *.c)

	zip_name="${i}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../gh-pages/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done

# Load the list of things to be documented: only elemtypes
doxyfiles=$(cat scripts/conf_elemtype.txt)
echo '******'
echo $doxyfiles
echo '******'

cwd=$(pwd)
for i in $doxyfiles; do
    echo "****************************************************"
	echo "* $i"
    echo "****************************************************"

	# Redirect both stderr and stdout to the log file and the console.
	cd elemtype/$i/doxygen
	doxygen 2>&1 | tee doxygen.log
	echo $(ls -l)
	cd $cwd

	################################################################################
	##### Copy generated doc from master folder to gh-pages one.               #####
	dir=gh-pages/elemtype/$i/html
	if [ -d "$dir" ]; then rm -Rf $dir; fi
	mkdir -p $dir
	mv elemtype/$i/doxygen/html gh-pages/elemtype/$i

	################################################################################
	##### Creation of the zip file for the download.                           #####
	cd elemtype/$i
	headers=$(ls *.h)
	sources=$(ls *.c)

	zip_name="elemtype_${i}.zip"
	echo ${zip_name}
	zip ${zip_name} -r ${headers} ${sources}

	file=../../gh-pages/elemtype/$i/${zip_name}
	if [ -f "$file" ]; then rm $file; fi
	mv ${zip_name} ${file}
	cd $cwd
done

echo $(ls -l gh-pages)