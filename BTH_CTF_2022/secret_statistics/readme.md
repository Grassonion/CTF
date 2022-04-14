# Secret Statistics

### Challenge description:
I am sure that i left my flag in the statistics somewhere, can you find it for me?
________________


### Walkthrough: 

We are given a PDF with these nice graphics:   

![alt text](imgs/pic1.png "pdf") 

Using binwalk we can see that there is a PNG at the very end of the PDF, this is also very obvious if the PDF is opened with a text editor.  
![alt text](imgs/pic2.png "pdf") 

Carving the image out and displaying it we get the flag:  
![alt text](imgs/win.png "pdf") 

