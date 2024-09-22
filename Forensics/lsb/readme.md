# Description
Guess what? This JPEG isn’t just a pretty picture. Dive into the pixel party and extract the hidden flag. The smallest details hold the biggest secrets! 🤫🔍


# solver 
use zsteg to extract lsb or you can craft a python script to extract it

```
╰─➤  zsteg output.png                               
imagedata           .. text: "+/CFJ$()"
b1,r,lsb,xy         .. text: "{Z=V^rw5S;BW,/"
b1,rgb,lsb,xy       .. text: "Securinets{Its here extract me} Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make "
b3,bgr,msb,xy       .. file: zlib compressed data
b4,r,lsb,xy         .. text: "3DTDUDEET"
b4,g,lsb,xy         .. text: "gvfwwffwwffwwf"
b4,b,lsb,xy         .. text: "TDEDUD##2##\"TDU\"2"
b4,rgb,lsb,xy       .. text: "Ct'bg7cgIt"
b4,bgr,lsb,xy       .. text: "sG$bg7ciG"
```

to extract all the data hidden in the lsbs
```
zsteg output.png -e b1,rgb,lsb,xy | head > file
```

then you will find a base64 there
```
╰─➤  echo "U2VjdXJpbmV0c3tIaWRkZW5faW5fdGhlX0xTQnN9Cg==" | base64 -d
Securinets{Hidden_in_the_LSBs}
```