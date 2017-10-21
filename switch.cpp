char Choice;
cout << "Enter the letter for your choice: ";
cin >> Choice;

switch(Choice)
{
case 'A':
case 'a':
DoOptionA();
break;
case 'B':
case 'b':
DoOptionB();
break;
case 'C':
case 'c':
DoOptionC();
break;
case 'D':
case 'd':
DoOptionD();
}