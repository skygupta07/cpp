/*

subset -> sequence (no) continuous (no)
subsequence-> sequence (yes) continuous (no)
substring -> sequence (yes) continuous (yes) 


-------------

for (int i=0; i<n; i++){    // syntax to generate substring...
    for (int j=i; j<n; j++){
        if ( isPalindrome(s, i, j)) count++;
    }
}

-----------
matlab har char pe jaake odd aur even length dono hi try karna hai jiski daal gali useey 
count increment karwa lena...

odd case mai bas neighbour ko dekhna hai... i-1 and i+1
and even wale case mai agar i aur i+1  equal honge tabhi uske left right mai aur bhi add
karke dekh payenge...

plus 1 karenge kyuki single length waala bhi to palindrome hoga hi...
side mai jaa rahe hai wo to acchi baat hai....






















*/