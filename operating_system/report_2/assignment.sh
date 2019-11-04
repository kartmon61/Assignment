#!/bin/bash 
#call shell environment

#print "File to read"
echo "File to read:"

#read File and save the variable in to readFile
read readFile

#print "original contents"
echo "original contents"

#show inside readFile contents
cat ${readFile}

#print "Search text:"
echo "Search text:"

#save variable in to search
read search

#print "Replacement text:"
echo "Replacement text:"

#save variable in to change
read change

#change contents variable in readFile search to change variable 
#save file into the readFile.txt
sed "s/${search}/${change}/g" ${readFile} > ${readFile}.txt

#overwrite readFile.txt to readFile
mv ${readFile}.txt ${readFile}
#print "change contents"
echo "change contents"

#show inside readFile contents
cat ${readFile}
