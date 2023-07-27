#include "knight.h"  
    
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
} 
//event15-16-17 
void event15_16_17(int c, int & remedy, int & maidenkiss, int & phoenixdown) {
    switch (c)
    {
    case 15: 
        if (remedy < 99) {
            remedy++; 
        }
        break;
    case 16: 
        if (maidenkiss < 99) {
            maidenkiss++; 
        }
        break;
    case 17: 
        if (phoenixdown < 99) {
            phoenixdown++; 
        }
        break; 
    }
}
//event1to5 
float msk(int eventcode) {
    if (eventcode == 1) { 
        return 1; 
    }
    if (eventcode == 2) { 
        return 1.5;
    }
    if (eventcode == 3) { 
        return 4.5;
    }
    if (eventcode == 4 ) {
        return 7.5; 
    }
    if (eventcode == 5) {
        return 9.5; 
    }
}
//checksnt
bool nguyento(int a) {  
    if (a<2) return false;  
    for (int i = 2; i < a ;i++) { 
        if (a%i == 0) return false; 
    }
    return true;
}

void event1to5(int i,int eventcode, int HP_MAX,int & HP, int & level, int & phoenixdown, int & rescue) {
    int levelO;
	int HPMAX = HP;  
    int b= i%10; 
    levelO = i > 6?(b > 5?b : 5) : b; 
    
    if ((level > levelO) || (nguyento(HP_MAX)) || (HP_MAX==999))  {
    		level++;
	} 
    if (level < levelO) {
        int damage = msk(eventcode)*levelO*10;
        
    	HP = HPMAX - damage;
        if (HP < 0 && phoenixdown != 0) { 
            phoenixdown--; 
            HP = HP_MAX;
        }
	} 
    
}
//event6
void event6(int i,int eventcode,int HP_MAX,int & HP, int & level, int & phoenixdown, int & remedy, int & rescue){ 
    int levelO;
    int HPMAX = HP;  
    int b= i%10; 
    levelO = i > 6?(b > 5?b : 5) : b;
    if ((level > levelO) || (nguyento(HP_MAX)) || (HP_MAX==999))  {
    	level = level + 2;
	} 
    if (level < levelO) {
    	if (HP > 0) {
           if (HP <=5) { 
                HP = 1; 
           } else { 
                HP = HPMAX/5;  
           } 
        } 
	} 
    
}
//event7 
void event7(int i,int n,int HP_MAX, int & HP, int & level, int & maidenkiss,int & remedy, int & rescue ){ 
    int levelO;
    //int HPMAX = HP;  
    int b= i%10; 
    levelO = i > 6?(b > 5?b : 5) : b;
    
    if ((level > levelO) || (nguyento(HP_MAX)) || (HP_MAX==999)) {
    		level = level + 2;
	}
    else if (level < levelO) {
        if (maidenkiss != 0) { 
            maidenkiss--; 
        } else {
            level = 1; 
            
        } 
	} 
    
}

//event11
void event11(int & HP,int & level, int & phoenixdown, int n,int HP_MAX) { 
    int n1=((level + phoenixdown)%5 + 1)*3;
    int s1=0;
    int HPi=99;
    for(int i=0;i<n1;i++){
        s1=s1+HPi;
        HPi-=2;
    }
    HP=HP+(s1%100);
    if (HP <= 1) HP=2;
    while(!nguyento(HP)){
        HP++;
    }
    if(HP>HP_MAX){
        HP = HP_MAX;
    }
    
}
int Fi(int n) { 
    int F=0,F1 = 1, F2 = 1; 
    if (n==2) return 1; 
    while(F1+F2 < n) { 
        F= F1+F2; 
        F1 = F2; 
        F2 = F; 
    }
    return F; 
}
//event12 fibonacci
void event12(int & HP,int & level, int & phoenixdown, int n){
    int check = HP; 
    if (HP > 1) { 
        HP = Fi(check); 
    } 
}

//event 18 19 13
string efile(string str3, int vitri) {
    stringstream ss; 
    ss << str3; 
    string asclepius_pack, merlin_pack, mush_ghost; 
    getline(ss, mush_ghost, ','); 
    getline(ss, asclepius_pack, ',');
    getline(ss,merlin_pack, ',');
    if (vitri == 1) { 
        
        return mush_ghost; 
    }
    if (vitri == 2) { 
       
        return asclepius_pack;  
    }
    if (vitri == 3) { 
        
        return merlin_pack; 
    }

}
int ismerlin(string check){
    for (int i=0;i<check.length(); i++)
    {
        if (check.substr(i,2) == "merlin" || check.substr(i,2) == "Merlin" )
        {
            return 3; 
        }
    }
    return 2;
}
void event13(string a,string str3 , int &HP ){
    int n2;
    int i=2;
    string mush[100];
    int fmush[100];
    int fmush4[100];
    int fmush3[100];
     ifstream mushghost(efile(str3,1));
    mushghost>>n2;
    mushghost.ignore();
    
    if(n2<=100){
        for(int i=0; i< n2 ;i++){
            getline(mushghost, mush[i], ',');
            fmush[i]=atoi(mush[i].c_str());
    }
    mushghost.close();
}
int max=fmush[0],max2;
int maxi,mtx,mti;
int min=fmush[0];
int mini;
bool checkl=true, checkr=true;
int maxi2=0, mini2=0;
int max2_3x, max2_3i;
    while(1){
            if(a[i]=='1'){
   for (int i=1 ;i<n2 ;i++) {
    maxi=0;mini=0;maxi2=0; mini2=0;
    max=fmush[0];min=fmush[0];
    if (max < fmush[i]) {max = fmush[i];
    maxi=i;}
    if (min > fmush[i]) {min = fmush[i];
    mini=i;}
   }
   //cout<<maxi<<" "<<mini<<endl;
   HP= HP-(maxi + mini);
   //cout<<HP<<endl;
            }
            if(a[i]=='2'){
                for (int i=1 ;i<n2 ;i++) {
    if (max < fmush[i]) {max = fmush[i];
    maxi=i;
        }
    }
   
    for (int i=0; i < maxi; i++){
        if ((fmush[i] > fmush[i+1])||(fmush[i]==fmush[i+1])){ 
            checkl=false;
            break;
        }
    }
    for (int i=maxi; i<n2-1 ;i++){
        if ((fmush[i] < fmush[i+1])||(fmush[i]==fmush[i+1])){
            checkr=false;
            break;
        }
    }
    if (checkl==true & checkr==true){
        mti=maxi;
        mtx=fmush[maxi];
    }
    else {mtx=-2; mti=-3;}
   //cout<< mtx<<" "<<mti<<endl;
    HP= HP-(mtx + mti);
    //cout<<HP<<endl;
            }
             if(a[i]=='3'){
                for (int i=0; i<n2 ;i++){
                    if (fmush[i]<0) fmush3[i]=-fmush[i]; else  fmush3[i]=fmush[i];   
                        fmush3[i]=(17 * fmush3[i] + 9)%257;
                       // cout<<fmush3[i]<<" ";
                }
                max=fmush3[0];
                min=fmush3[0];
                for (int i=1 ;i<n2 ;i++) {
    if (max < fmush3[i]) {max = fmush3[i];
    maxi2=i;}
    if (min > fmush3[i]) {min = fmush3[i];
    mini2=i;}
    
   }
   //cout<<maxi2<<" "<<mini2<<endl;
        HP=HP - (maxi2+mini2);
        
            }
             if(a[i]=='4'){
                for (int i=0; i<3 ;i++){
                     if (fmush[i]<0) fmush4[i]=-fmush[i]; else  fmush4[i]=fmush[i];
                        
                        fmush4[i]=(17 * fmush4[i] + 9)%257;
                    //cout<<fmush4[i]<<" ";
                }
                max=fmush4[0];
                 for (int i=1 ;i<3 ;i++) {
                   
    if (max < fmush4[i]) {max = fmush4[i];}
    }

    if (max==fmush4[0])  max2=fmush4[1];
    else 
        max2=fmush4[0];
            for (int i=0; i<3 ;i++){
                  if(fmush4[0]==fmush4[1] && fmush4[1]==fmush4[2]) {max2=-5; max2_3i=-7;break;}
                if ((fmush4[i] == fmush4[i+1]) || (fmush4[i] == fmush4[i+2])) {max2=fmush4[i]; max2_3i=i;}
                    if ((max2 <= fmush4[i]) && (fmush4[i] != max)) {
                        max2=fmush4[i]; max2_3i=i;
                    }
                   
                }
                
    max2_3x=max2;
   //cout<<max2_3x<<" "<<max2_3i<<endl;
        HP=HP - (max2_3i+max2_3x);
       
            }
             if(a[i]=='\0')
                break;
            
    i++;}
}
void event18(string str3, int & HP) {    
    string s; 
    ifstream merlinpack(efile(str3,3)); 
    getline(merlinpack, s); 
    int n9 = atoi(s.c_str()); 
    string items[n9]; 
    for (int i = 0; i < n9; i++) { 
        getline(merlinpack,items[i]); 
        HP += ismerlin(items[i]); 
    }
    merlinpack.close(); 
}
void event19(string str3, int & remedy, int & phoenixdown, int & maidenkiss) { 
    int r1, c1;
    int take;
    int a[100][100];
    ifstream asclepius(efile(str3,2));  
    asclepius>>r1; 
    asclepius>>c1;
    //cout<<r1<<" "<<c1<<endl;
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            asclepius>> a[i][j];
    //cout<<a[i][j]<<endl;
        }
    }
    asclepius.close();
    for(int i=0; i<r1; i++){ take=0;
        for(int j=0; j<c1; j++){
            if (a[i][j]==16) {remedy++;take++;}
            if (a[i][j]==17) {maidenkiss++;take++;}
            if (a[i][j]==18) {phoenixdown++;take++;}
            if (take==3) break;
        }
    }
}
void bowser(int & HP, int & level, int & rescue) {
     if ((HP==999) || ( nguyento(HP) && level>=8) || (level==10)) level=10;
     else rescue =0; 
}
//normal 
int normalHP(int dem, int c, int & HP, int n, int & remedy) {
    for (int i = dem; i <= (dem+3); i++ ) { 
        if (c == dem & remedy != 0) { 
            remedy--;
            return HP*5; 
        } else { 
            if (c == (dem+3)) { 
                return HP*5;
            } else return HP; 
        }
    }
}

int normallevel(int checklevel, int find, int c, int & maidenkiss) {
    int a  = checklevel;
    for (int i = find;i <= (find+3); i++) {
        if (c == find & maidenkiss != 0) { 
            maidenkiss--;
            return a; 
            break;
        }
         else if (c == (find +3)) 
                return a; 
             else {return 1;}
        
    }
}
//info 
void info(string str1,int & HP, int & level, int & remedy,int & maidenkiss, int & phoenixdown, int & rescue) { 
    int arr1[5]; 
    int k = 0; 
    string value; 
    for (int i = 0; i < str1.length(); i++) { 
        if (str1[i] != ' ') value = value + str1[i];
        else {
            arr1[k] = atoi(value.c_str()); 
            k+=1; 
            value = ""; 
        }
    }
    arr1[4] = atoi(value.c_str()); 
    //Thongtinhiepsi 
    HP = arr1[0]; 
    level = arr1[1]; 
    remedy = arr1[2]; 
    maidenkiss = arr1[3]; 
    phoenixdown = arr1[4];
}
//slove
void check(string event,string str3, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) { 
    int n= 0;
    int HP_MAX = HP;     
    int dem=0; 
    int find=0; 
    int checklevel;
    int checkHP;   
    int meet = 0, meet2=0;
    bool loss = 0;
    string value; 
    string arr[18]; 
    for (int i = 0; i < event.length(); i++) { 
        if (event[i] != ' ') value = value + event[i];
        else { 
            arr[n] = value; 
            n +=1; 
            value = ""; 
        } 
    } 
    arr[n] = value; 
    rescue = -1;
    for (int i = 0; i <= n ; i++ ) {
        if (HP < 0) {
            rescue = 0;
        }
        if (arr[i] == "0") {  
            rescue = 1;
        }
         if (arr[i] == "1") event1to5(i+1,1,HP_MAX,HP,level,phoenixdown,rescue);
        else if (arr[i] == "2") event1to5(i+1,2,HP_MAX,HP,level,phoenixdown,rescue);
        else if (arr[i] == "3") event1to5(i+1,3,HP_MAX,HP,level,phoenixdown,rescue);
        else if (arr[i] == "4") event1to5(i+1,4,HP_MAX,HP,level,phoenixdown,rescue);
        else if (arr[i] == "5") event1to5(i+1,5,HP_MAX,HP,level,phoenixdown,rescue);
        else if (arr[i] == "6") {
            event6(i+1,n,HP_MAX,HP,level,phoenixdown,remedy,rescue);  
            dem = i;             
        }
        else if (arr[i] == "7") { 
            checklevel = level; 
            if (i < (dem+4)) { 
                event7(i+1,n,HP_MAX,HP,level,maidenkiss,remedy,rescue);
                find = i;
            } 
        }
        else if (arr[i] == "11") { 
            event11(HP,level, phoenixdown, n,HP_MAX); 
        } 
        else if (arr[i] == "12") { 
            event12(HP,level,phoenixdown,n); 
        } 
        else if (arr[i] == "15") event15_16_17(15, remedy, maidenkiss,phoenixdown);
        else if (arr[i] == "16") event15_16_17(16, remedy, maidenkiss,phoenixdown);
        else if (arr[i] == "17") event15_16_17(17, remedy, maidenkiss,phoenixdown); 
        else if ((arr[i] == "18") && (meet2==0)) {
            event18(str3, HP); 
            meet2++;
        }
        else if ((arr[i] == "19") && (meet == 0)) {
            event19(str3, remedy, phoenixdown, maidenkiss);
            meet++;             
        }
        else if (arr[i] == "99") {
            bowser(HP_MAX,level,rescue);
            
        }
        else {
            if(arr[i].find("13")==0){
                event13(arr[i], str3, HP);
            }
        }
        
       if (remedy>99) remedy=99;
       if (phoenixdown>99) phoenixdown=99;
       if (maidenkiss>99) phoenixdown=99;
        if (dem != 0) {  
            HP = normalHP(dem,i,HP,n,remedy);
        }
         if (find != 0) {
            level = normallevel(checklevel,find, i,maidenkiss); 
           
        }
         if (rescue == 0) { 
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break; 
        }
        if (level > 10) level =10; 
        if (HP > HP_MAX) HP=HP_MAX;
        if (HP <= 0 && phoenixdown <= 0) rescue = 0;
        if (HP <= 0 && phoenixdown > 0) { 
            HP = HP_MAX; 
            phoenixdown--;  
            dem = 0; 
            find = 0; 
        } 
        if (i == n && HP > 0) rescue = 1;   
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        if (rescue == 0 || rescue == 1) break; 
       } 
   
}
//chuongtrinh
void adventureToKoopa(string file_input,int & HP, int & level, int & remedy,int & maidenkiss, int & phoenixdown, int & rescue) {
    string str1, event, str3; 
    ifstream File(file_input); 
    getline(File, str1); 
    getline(File, event); 
    getline(File, str3);    
    info(str1, HP, level, remedy, maidenkiss, phoenixdown, rescue);  
    check(event,str3, HP,level, remedy, maidenkiss, phoenixdown, rescue);
    File.close();
}
