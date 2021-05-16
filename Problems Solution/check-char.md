# [ Problem : Check Char ] 🐣
## Problem : คำถาม 🐣
>รับตัวอักษร มา 1 ตัว<ul>
    <li> ถ้าหากว่าเป็น สระ แสดงว่า vowels</li>
    <li> ถ้าหากว่าเป็น พยัญชนะ แสดงว่า Alphabets</li>
    <li> ถ้าหากว่าเป็น อักขระพิเศษ แสดงว่า not Alphabets</li>
    <br>
</ul>
<br>

## Solution : แนวคิด 🐣
>ใช้ if-else ตรวจที่ละเงื่อนไข โดยพิจารณาจากรหัส ascii เช่น A มีค่า 65 , a มีค่า 97 เป็นต้น

<br>

## Code : ภาษา C 🐣
```c
#include <stdio.h>

int main(){
    char c;
    scanf("%c",&c);

    if(c=='A' or c=='a' or c=='E' or c=='e' or c=='I' or c=='i' or c=='O' or c=='o' or c=='U' or c=='u'){
        printf("vowels\n");
    }else if((c>='A' and c<='Z') or (c>='a' and c<='z')){
        printf("Alphabets\n");
    }else{
        printf("not Alphabets\n");
    }

    return 0;
}
```

# ระดับความยาก : ⭐⭐⭐