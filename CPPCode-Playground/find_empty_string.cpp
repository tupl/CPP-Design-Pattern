/* Search */
// always shorten the white ending
// remove '' last
// get middle
// if middle '', increase mid

while (first <= last) {
    while(first <= last && str[last] == "") {
        -- last;
    }
    if (first > last) return -1;
    int mid = (first + last) >> 1;
    while (str[mid] == "") ++mid;
    if (str[mid] == val) return 0;
    else if (str[mid] < val){
        first = mid + 1;
    } else {
        last = mid - 1;
    }
}

//================== Tower ==================
