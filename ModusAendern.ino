/**************************************************************
ModusAendern
***************************************************************/ 
void ModusAendern() {

  switch(Menue) {

    // *** ch.1 ************************************************
    case 1:
        ModusName = "Ch. #1   ";
        ModusAktion = "flash       ";
        code = "110100110010100001"; // *** (OK!)
        art = 0;
    break;

    case 2:
        ModusName = "Ch. #1   ";
        ModusAktion = "Licht n/c       ";
        code = "0";  
        art = 1;
    break;
    
    case 3:
        ModusName = "Ch. #1   ";
        ModusAktion = "power up        ";
        code = "110010011010100000"; // *** (OK!)
        art = 1;
    break;

    case 4:
        ModusName = "Ch. #1    ";
        ModusAktion = "power down      ";
        code = "001001101010000010"; // *** (OK!)
        art = 1;
    break;




    // *** ch.2 ************************************************
    case 5:
        ModusName = "Ch. #2   ";
        ModusAktion = "flash           ";
        code = "110100110010100011"; // *** (OK!)  
        art = 0;
    break;

    case 6:
        ModusName = "Ch. #2   ";
        ModusAktion = "Licht n/c       ";
        code = "0"; 
        art = 1;
    break;
    
    case 7:
        ModusName = "Ch. #2    ";
        ModusAktion = "power up        ";
        code ="110010011010100010"; // *** (OK!)
        art = 1;
    break;

    case 8:
        ModusName = "Ch. #2    ";
        ModusAktion = "power down      ";
        code = "001001101010001010"; // *** (OK!)
        art = 1;
    break;



    // *** ch.3 ************************************************
    case 9:
        ModusName = "Blitz #3  ";
        ModusAktion = "flash           ";
        code = "110100110010100101"; // *** (OK!)
        art = 0;
    break;

    case 10:
        ModusName = "Ch. #3    ";
        ModusAktion = "Licht n/c       ";
        code = "0";  
        art = 1;
    break;
    
    case 11:
        ModusName = "Ch. #3  ER";
        ModusAktion = "power up        ";
        code = "110010011010100100";  // *** (OK!)
        art = 1;
    break;

    case 12:
        ModusName = "Ch. #3     ";
        ModusAktion = "power down      ";
        code = "001001101010010010"; // *** (OK!)
        art = 1;
    break;



    // *** ch.all ************************************************
    case 13:
        ModusName = "Ch. #all   ";
        ModusAktion = "flash           ";
        code = "110100110010100111"; // *** (OK!)
        art = 0;
    break;

    case 14:
        ModusName = "Ch. #all ER";
        ModusAktion = "Licht n/c       ";
        code = "0";   
        art = 1;
    break;
    
    case 15:
        ModusName = "Ch. #all   ";
        ModusAktion = "power up        ";
        code = "110010011010100110"; // *** (OK!)
        art = 1;
    break;

    case 16:
        ModusName = "Ch. #all   ";
        ModusAktion = "power down      ";
        code = "001001101010011010"; // *** (OK!)
        art = 1;
    break;

 
 }  
 
}
