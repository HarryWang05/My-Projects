//Author: Harry Wang
//Date: May 26 2021
//Description: Same as my python version, but in javascript. Requires Node.js.

const readline = require('readline');

function quick_sort(data) {
    //console.log("data");
    //console.log(data);
    var l, pivot, item
    var greater_list = [];
    var lower_list = [];
    l = data.length;
    if(l <= 1) {
        return data;
    } else {
        pivot = data.pop();
    }
    for(var i = 0; i < l-1; i++) {
        item = data[i];
        if(item > pivot) {
            //console.log(i.toString()+" Greater: "+item.toString());
            greater_list.push(item);
        } else {
            //console.log(i.toString()+" Lower: "+item.toString());
            lower_list.push(item);
        }
    }
    var pivot_list = [pivot];
    return quick_sort(lower_list).concat(pivot_list).concat(quick_sort(greater_list));
}
const aIn = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

aIn.question('Input list with integers, all elements seperated by a space\n', arrayInput => {
    console.log(quick_sort(arrayInput.split(" ").map(x => parseInt(x))));
    aIn.close();
});