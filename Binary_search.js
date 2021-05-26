//Author: Harry Wang
//Date: May 26 2021
//Description: Same as my python version, but in javascript. Requires Node.js.

const readline = require('readline');

function binary_search(search, data) {
  begin_index = 0;
  end_index = data.length-1;
  while(begin_index <= end_index) {
    midpoint = begin_index + Math.floor((end_index-begin_index)/2);
    midpoint_value = data[midpoint];
    if(midpoint_value == search) {
      return midpoint;
    } else if(midpoint_value < search) {
      //Beginning index is to the right of midpoint
      begin_index = midpoint+1;
    } else {
      //Ending index is to the left of midpoint
      end_index = midpoint-1;
    }
  }
  return search.toString()+" is not in this array";
}
var searchIn, dataIn;

const aIn = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

aIn.question("Input element to search for\n", firstIn => {
    searchIn = parseInt(firstIn);
    aIn.close();
    const bIn = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });
    bIn.question("Input list with integers, all elements seperated by a space\n", secondIn => {
        dataIn = secondIn.split(' ').map(x => parseInt(x));
        console.log(binary_search(searchIn,dataIn));
        bIn.close();
    });
});