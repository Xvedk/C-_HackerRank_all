 cout << left << hex 
        << showbase << nouppercase 
        << (long)A << endl;
    
    cout << right << fixed << setw(15) 
        << showpos << setprecision(2) 
        << setfill('_') << B << endl;
    
    //cout << setiosflags(ios::uppercase) << setiosflags(ios::scientific); 
    cout << setprecision(9)
        << scientific << noshowpos << uppercase  
        << C << endl; 

    }
    return 0;
       
