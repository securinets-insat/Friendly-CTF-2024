# Description
There’s a hidden secret lurking in this image.


# solver

```
╰─➤  exiftool hidden.jpeg
ExifTool Version Number         : 12.96
File Name                       : hidden.jpeg
Directory                       : .
File Size                       : 57 kB
File Modification Date/Time     : 2024:09:09 22:43:01+01:00
File Access Date/Time           : 2024:09:22 11:56:35+01:00
File Inode Change Date/Time     : 2024:09:09 22:45:01+01:00
File Permissions                : -rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Resolution Unit                 : None
X Resolution                    : 1
Y Resolution                    : 1
Comment                         : I hid something with this password '5bdae6bb388d42ef73570336d8babd42'. Can you see it?
```
<br>
we can use this password to extract a secret with steghide

```
╰─➤  steghide extract -sf hidden.jpeg -xf extracted_secret.txt
```