#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define int long long int
const int INF=1000;
bool random=true;
bool gameOver=false;
int brute=0;
//0==>pink  1==>blue   2==>green  3==>yellow  4==>white -1==>goverment
class board;
void buyPlace(board&,bool);
void sellHouse(board & brd);
void sellPlace(board & brd);
void buyHouse(board & brd);
int companyRent(int dice,board & brd);
void communityChest(int dice,board& brd);
void CHANCE(int dice,board &brd);
vector<int>color={-1,0,4,4,0,-1,1,-1,1,-1,2,2,4,4,3,3,-1,3,-1,1,-1,1,1,0,4,0,0,-1,3,-1,3,-1,2,2,4,2};
vector<string>colordecode={"Pink   ","Blue   ","Green  ","Yellow ","White  "};
vector<string>names(36);
vector<int>costs(36),buildcosts(36);
vector<vector<int>>rents(36);


void inputint(int &x,int low=0,int high=1e9,bool dice=false){
    if(random && dice){
        x=1+(rand()%6);
        cout<<x<<' ';
        return;
    }
    if(brute){
        if(high==1)x=0;else x=6;
        brute--;
        return;
    }
    string s;cin>>s;bool autoMove=false;
    if(s=="108"){
        gameOver=true;return;
    }
    if(s.length()>1 && s[0]=='@'){
        reverse(begin(s),end(s));
        s.pop_back();
        reverse(begin(s),end(s));
        autoMove=true;
    }
    bool f=true;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            continue;
        }
        f=false;
    }

    if(f){

        x=stoi(s);
        if(autoMove){
            brute+=x;return;
        }
        if(x<low || x>high){
            cout<<"number is out of range please enter from {"<<low<<','<<high<<"}:";
            inputint(x,low,high);
        }
        else return;
    }
    else{
        cout<<"Please type a valid integer:";
        inputint(x,low,high);
    }
}
void setnames(){
    names[0]="START";    
    names[1]="MUMBAI";
    names[2]="WATER WORKS";
    names[3]="RAILWAYS";
    names[4]="AHMEDABAD";
    names[5]="INCOME TAX";
    names[6]="INDORE";
    names[7]="CHANCE";
    names[8]="JAIPUR";
    names[9]="JAIL";
    names[10]="NEW DELHI";
    names[11]="CHANDIGARH";
    names[12]="ELECTRIC COMPANY";
    names[13]="BEST";
    names[14]="SHIMLA";
    names[15]="AMRITSAR";
    names[16]="COMMUNITY CHEST";
    names[17]="SHRINAGAR";
    names[18]="CLUB";
    names[19]="AGRA";
    names[20]="CHANCE";
    names[21]="KANPUR";
    names[22]="PATNA";
    names[23]="DARJEELING";
    names[24]="AIR INDIA";
    names[25]="KOLKATTA";
    names[26]="HYDERABAD";
    names[27]="REST HOUSE";
    names[28]="CHENNAI";
    names[29]="COMMUNITY CHEST";
    names[30]="BENGALURU";
    names[31]="INCOME TAX";
    names[32]="MYSORE";
    names[33]="COCHIN";
    names[34]="MOTOR BOAT";
    names[35]="GOA";
}
void setcost(){
    costs[0]=INF;
    costs[1]=8500;
    costs[2]=3200;
    costs[3]=9500;
    costs[4]=4000;
    costs[5]=INF;
    costs[6]=1500;
    costs[7]=INF;
    costs[8]=3000;
    costs[9]=INF;
    costs[10]=6000;
    costs[11]=2500;
    costs[12]=2500;
    costs[13]=3500;
    costs[14]=2200;
    costs[15]=3300;
    costs[16]=INF;
    costs[17]=5000;
    costs[18]=INF;
    costs[19]=2500;
    costs[20]=INF;
    costs[21]=4000;
    costs[22]=2000;
    costs[23]=2500;
    costs[24]=10500;
    costs[25]=6500;
    costs[26]=3500;
    costs[27]=INF;
    costs[28]=7000;
    costs[29]=INF;
    costs[30]=4000;
    costs[31]=INF;
    costs[32]=2500;
    costs[33]=3000;
    costs[34]=5500;
    costs[35]=4000;
}
void setrent(){
    rents[0]={INF,INF,INF,INF,INF};//*
    rents[1]={1200,4000,5500,7500,9000};
    rents[2]={INF,INF,INF,INF,INF};//*
    rents[3]={INF,INF,INF,INF,INF};//*
    rents[4]={400,1500,3000,4200,5000};
    rents[5]={INF,INF,INF,INF,INF};//*
    rents[6]={200,600,1500,2500,3600};
    rents[7]={INF,INF,INF,INF,INF};
    rents[8]={250,1500,2750,4000,5500};
    rents[9]={INF,INF,INF,INF,INF};
    rents[10]={750,3000,4300,5500,7500};
    rents[11]={200,900,1600,2500,3500};
    rents[12]={INF,INF,INF,INF,INF};//*
    rents[13]={INF,INF,INF,INF,INF};//*
    rents[14]={200,1000,2750,4500,6000};
    rents[15]={300,1400,2800,4000,5000};
    rents[16]={INF,INF,INF,INF,INF};//*
    rents[17]={550,3500,5000,7000,8000};
    rents[18]={INF,INF,INF,INF,INF};//*
    rents[19]={200,900,1600,2500,3500};
    rents[20]={INF,INF,INF,INF,INF};//*
    rents[21]={400,1500,3000,4500,5500};
    rents[22]={150,800,2000,3000,4500};
    rents[23]={200,1200,2600,3500,5000};
    rents[24]={INF,INF,INF,INF,INF};//*
    rents[25]={800,3200,4500,6500,8000};
    rents[26]={300,1200,3000,4500,6000};
    rents[27]={INF,INF,INF,INF,INF};//*
    rents[28]={900,3500,5000,7000,8500};
    rents[29]={INF,INF,INF,INF,INF};//*
    rents[30]={400,1500,3000,4500,5500};
    rents[31]={INF,INF,INF,INF,INF};//*
    rents[32]={200,1000,2250,3500,4500};
    rents[33]={300,1200,2000,4250,5500};
    rents[34]={INF,INF,INF,INF,INF};//*
    rents[35]={400,2200,3500,5000,6500};
}
void setbuiltcost(){
    buildcosts[0]=INF;
    buildcosts[1]=7500;
    buildcosts[2]=INF;
    buildcosts[3]=INF;
    buildcosts[4]=4500;
    buildcosts[5]=INF;
    buildcosts[6]=2000;
    buildcosts[7]=INF;
    buildcosts[8]=4000;
    buildcosts[9]=INF;
    buildcosts[10]=5000;
    buildcosts[11]=3000;
    buildcosts[12]=INF;
    buildcosts[13]=INF;
    buildcosts[14]=3500;
    buildcosts[15]=4500;
    buildcosts[16]=INF;
    buildcosts[17]=6000;
    buildcosts[18]=INF;
    buildcosts[19]=3000;
    buildcosts[20]=INF;
    buildcosts[21]=4500;
    buildcosts[22]=2500;
    buildcosts[23]=3000;
    buildcosts[24]=INF;
    buildcosts[25]=6000;
    buildcosts[26]=5000;
    buildcosts[27]=INF;
    buildcosts[28]=6500;
    buildcosts[29]=INF;
    buildcosts[30]=4500;
    buildcosts[31]=INF;
    buildcosts[32]=3000;
    buildcosts[33]=4000;
    buildcosts[34]=INF;
    buildcosts[35]=4500;
}
class place{
    public:
        int buildcost=2000;
        int occupied=-1;
        vector<int>rent;
        int cost=1000;
        string name="START";
        place(){

        }
};
class player{
    
    public:
        vector<int>rentLevel;
        vector<vector<int>>property;
        int cash=49950;int assets=0;
        string name;
        int currentlocation=0;
        int stop=0;
        player(){
            rentLevel.resize(4);
            property.resize(5);
        }
        void set(){
            rentLevel.resize(4);
            property.resize(5);
        }
        void printProperty(){
            for(int i=0;i<5;i++){
                cout<<colordecode[i]<<"==>";
                for(int j=0;j<property[i].size();j++){
                    cout<<" "<<names[property[i][j]]<<" ";
                }cout<<endl;
            }
        }
};
class board{
    int size=36;
    protected:
    public:
        vector<bool>house;
        vector<place>location;
        int numberofplayers=2;
        vector<player>players;
        int jailPenulty=300;
        int currentplayer=0;
    board(int x){
            location.resize(36);
            house.resize(35);
            numberofplayers=x;
            players.resize(x);
            for(int i=0;i<numberofplayers;i++){
                players[i].set();
                players[i].name="Player "+to_string(i+1);
            }
            for(int i=0;i<36;i++){
                location[i].name=names[i];
                location[i].cost=costs[i];
                location[i].buildcost=buildcosts[i];
                location[i].rent=rents[i];
            }
            location[0].occupied=10;location[9].occupied=10;location[18].occupied=10;location[27].occupied=10;
            location[7].occupied=10;location[20].occupied=10;
            location[16].occupied=10;location[29].occupied=10;
            location[5].occupied=10;location[31].occupied=10;
        }
    void interaction(){
        buyPlace(*this,false);
        cout<<"1:BuyPlace 2:BuyHouse 3:SellPlace 4:sellHouse 5:showProperty 6:Exit :: ";
        int option ;inputint(option,1,6);
        while(true){
            if(gameOver)return;
            if(option==1)buyPlace(*this,true);//
            if(option==2)buyHouse(*this);//
            if(option==3)sellPlace(*this);//
            if(option==4)sellHouse(*this);//
            if(option==5)players[currentplayer].printProperty();
            if(option==6 )return;
            cout<<"1:BuyPlace 2:BuyHouse 3:SellPlace 4:sellHouse 5:showProperty 6:Exit :: ";inputint(option,1,6);
        }
    }
    void status(){
        cout<<"Player   ::   Balance   ::   Current location"<<endl;
        for(int i=0;i<players.size();i++){
            cout<<players[i].name<<" ::   "<<players[i].cash<<"/-   ::   "<<location[players[i].currentlocation].name<<"["<<players[i].currentlocation<<"]"<<endl;
        }
    }
    void payRent(int dice){
        auto currentLocation=location[players[currentplayer].currentlocation]; 
        if(currentLocation.occupied!=currentplayer && currentLocation.occupied!=10 && currentLocation.occupied!=-1){
            int rentToPay;
            if(house[players[currentplayer].currentlocation]){
                rentToPay=currentLocation.rent[players[currentLocation.occupied].rentLevel[color[players[currentplayer].currentlocation]]];
                
            }
            else if(color[players[currentplayer].currentlocation]==4){
                rentToPay=companyRent(dice,*this);
            }
            else{
                rentToPay=currentLocation.rent[0];
                
            }
            cout<<"You are at "<<players[currentLocation.occupied].name<<"'s property you have to pay a rent of Rs."<<rentToPay<<"/- ."<<endl;
            players[currentplayer].cash-=rentToPay;
            players[currentLocation.occupied].cash+=rentToPay;
        }
    }
    void playMove(int turn,int dice1,int dice2){
        int initiallocation=players[turn].currentlocation;
        players[turn].currentlocation+=(dice1+dice2);
        players[turn].currentlocation%=36;
        int finallocation=players[turn].currentlocation;
        auto currentLocation=location[players[currentplayer].currentlocation];
        cout<<endl<<players[turn].name<<" : "<<names[initiallocation]<<" ===> "<<names[finallocation]<<endl;
        //COMMUNITY CHEST
        if(location[players[currentplayer].currentlocation].name=="COMMUNITY CHEST"){
            communityChest(dice1+dice2,*this);
        }
        //CHANCE
        if(location[players[currentplayer].currentlocation].name=="CHANCE"){
            CHANCE(dice1+dice2,*this);
        }
        //Cross START
        if(initiallocation>18 && players[currentplayer].currentlocation<18){
            cout<<players[currentplayer].name<<" has completed a round collect Rs.1500/- from Bank ."<<endl;
            players[currentplayer].cash+=1500;
        }
        //CLUB
        if(location[players[currentplayer].currentlocation].name=="CLUB"){
            cout<<"Give party of Rs. 50/- to all other players ."<<endl;
            for(int i=0;i<numberofplayers;i++){
                players[i].cash+=50;
                players[currentplayer].cash-=50;
            }
        }
        //REST HOUSE
        if(location[players[currentplayer].currentlocation].name=="REST HOUSE"){
            cout<<"Collect Rs. 50/- from each player and do rest ."<<endl;
            for(int i=0;i<numberofplayers;i++){
                players[i].cash-=50;
                players[currentplayer].cash+=50;
            }
        }
        //JAIL
        if(location[players[currentplayer].currentlocation].name=="JAIL"){
            cout<<"You are in JAIL you will not play next move"<<endl;
            players[currentplayer].stop+=2;
        }
        //IncomeTax
        if(location[players[currentplayer].currentlocation].name=="INCOME TAX"){
           int tax=players[currentplayer].property[0].size()*50;
            tax+=players[currentplayer].property[1].size()*50;
            tax+=players[currentplayer].property[2].size()*50;
            tax+=players[currentplayer].property[3].size()*50;
            cout<<players[currentplayer].name<<" has to pay INCOME TAX of "<<tax<<'.'<<endl; 
        }
    }
};
void buyPlace(board & brd,bool byChoice){
    auto currentLocation=brd.location[brd.players[brd.currentplayer].currentlocation];
    if(currentLocation.occupied==10 ){
        if(!byChoice)return;
        cout<<"Its a government Property ."<<endl;return;
    }
    if(currentLocation.occupied==brd.currentplayer){
        if(!byChoice)return;
        cout<<"You already own this property ."<<endl;return;
    }
    if(currentLocation.occupied!=-1){
        if(!byChoice)return;
        cout<<"Its "<<brd.players[currentLocation.occupied].name<<"'s property ."<<endl;return;
    }
    if(brd.players[brd.currentplayer].cash<brd.location[brd.players[brd.currentplayer].currentlocation].cost){
       cout<<"You don't have enough money to buy this place ."<<endl;
       return;     
    }
    cout<<"Do you want to buy "<<currentLocation.name<<" in Rs."<<currentLocation.cost<<"/- (0/1) :";int option;inputint(option,0,1);
    if(option==0)return;
    brd.location[brd.players[brd.currentplayer].currentlocation].occupied=brd.currentplayer;
    brd.players[brd.currentplayer].cash-=currentLocation.cost;
    brd.players[brd.currentplayer].assets+=currentLocation.cost;
    int x=brd.players[brd.currentplayer].currentlocation;
    brd.players[brd.currentplayer].property[color[x]].push_back(x);
    cout<<"Now you are the owner of "<<currentLocation.name<<" ."<<endl;
}
void buyHouse(board & brd){
    cout<<"PINK(0) BLUE(1) GREEN(2) YELLOW(3) :";
    int option;inputint(option,0,3);
    auto &availablePlaces=brd.players[brd.currentplayer].property[option];
    if(availablePlaces.size()<3){
        cout<<"You dont have enough places to build a house of this type ."<<endl;
        return;
    }
    cout<<"SELECT A PLACE :";
    for(int i=0;i<availablePlaces.size();i++){
        cout<<i+1<<'.'<<names[availablePlaces[i]]<<"(Rs."<<brd.location[availablePlaces[i]].buildcost<<"/-) ";
    }cout<<":";
    inputint(option,1,availablePlaces.size());
    int requiredcost=brd.location[availablePlaces[option-1]].buildcost;
    if(brd.players[brd.currentplayer].cash<requiredcost){
        cout<<"You dont have enough money to build a house here ."<<endl;
        return;
    }
    int requiredplace=availablePlaces[option-1];
    if(brd.house[requiredplace]){
        cout<<"You already have house here ."<<endl;return;
    }
    cout<<"Do you want to build a house at "<<names[availablePlaces[option-1]]<<" at cost Rs."<<requiredcost<<"/- (0/1):";
    inputint(option,0,1);
    if(option==0)return;
    brd.house[requiredplace]=true;names[requiredplace].push_back('*');
    brd.players[brd.currentplayer].rentLevel[color[requiredplace]]++;
    brd.players[brd.currentplayer].cash-=requiredcost;
}
void sellHouse(board & brd){
    cout<<"PINK(0) BLUE(1) GREEN(2) YELLOW(3) :";
    int option;inputint(option,0,3);
    auto &availablePlaces=brd.players[brd.currentplayer].property[option];
    vector<int>houseLocations;
    for(int i=0;i<availablePlaces.size();i++){
        if(brd.house[availablePlaces[i]]){
            houseLocations.push_back(availablePlaces[i]);
        }
    }
    if(houseLocations.size()==0){
        cout<<"You dont have any house of this type ."<<endl;return;
    }
    cout<<"SELECT HOUSE TO SELL:";
    for(int i=0;i<houseLocations.size();i++){
        cout<<" "<<i+1<<'.'<<names[houseLocations[i]]<<"(Rs."<<brd.location[availablePlaces[i]].buildcost/2<<"/-) ";
    }inputint(option,1,houseLocations.size());
    int requiredLocation=houseLocations[option-1];
    int requiredMoney=brd.location[availablePlaces[option-1]].buildcost/2;
    cout<<"Do you want to sell the house at "<<names[requiredLocation]<<" in Rs."<<requiredMoney<<"/- (0/1) :";inputint(option,0,1);
    if(option==0)return;
    brd.house[requiredLocation]=false;
    brd.players[brd.currentplayer].rentLevel[color[requiredLocation]]++;
    brd.players[brd.currentplayer].cash+=requiredMoney;

}
void sellPlace(board & brd){
    cout<<"PINK(0) BLUE(1) GREEN(2) YELLOW(3) WHITE(4) :";
    int option;inputint(option,0,4);
    auto &availablePlaces=brd.players[brd.currentplayer].property[option];
    int numberofhouses=0; 
    if(availablePlaces.size()==0){
        cout<<"You dont have any place of this type ."<<endl;return;
    }cout<<"SELECT A PLACE :";
    for(int i=0;i<availablePlaces.size();i++){
        cout<<i+1<<'.'<<names[availablePlaces[i]]<<"(Rs."<<brd.location[availablePlaces[i]].cost/2<<"/-)";
        if(brd.house[availablePlaces[i]])numberofhouses++;
    }cout<<":";inputint(option,1,availablePlaces.size());
    int requiredMoney=brd.location[availablePlaces[option-1]].cost/2;
    int requiredPlace=availablePlaces[option-1];
    auto it=availablePlaces.begin()+option-1;
    if(brd.house[requiredPlace]){
        cout<<"This place contains a house you cant sell it ."<<endl;return;
    }
    if(availablePlaces.size()==3 && numberofhouses!=0){
        cout<<"You have to sell all your houses of this type to sell this ."<<endl;
        return;
    }
    cout<<"Do you want to sell "<<names[requiredPlace]<<" for Rs."<<requiredMoney<<"/- (0/1):";inputint(option,0,1);
    if(option==0)return;
    brd.location[requiredPlace].occupied=-1;
    brd.players[brd.currentplayer].cash+=requiredMoney;
    brd.players[brd.currentplayer].assets-=requiredMoney;
    availablePlaces.erase(it);
}
int companyRent(int dice,board & brd){
    auto currentLocation=brd.location[brd.players[brd.currentplayer].currentlocation];
    auto companyOwner=currentLocation.occupied;
    int rent=0;
    if(currentLocation.name=="WATER WORKS"){
        if(brd.location[24].occupied==companyOwner){
            rent=100;
        }
        else{
            rent=500;
        }
    }
    if(currentLocation.name=="RAILWAYS"){
        if(brd.location[24].occupied==companyOwner){
            rent=1350;
        }
        else{
            rent=1000;
        }
    }
    if(currentLocation.name=="ELECTRIC COMPANY"){
        if(brd.location[34].occupied==companyOwner){
            rent=100*dice;
        }
        else{
            rent=50*dice;
        }
    }
    if(currentLocation.name=="BEST"){
        if(brd.location[3].occupied==companyOwner){
            rent=110;
        }
        else{
            rent=600;
        }
    }
    if(currentLocation.name=="AIR INDIA"){
        if(brd.location[2].occupied==companyOwner){
            rent=1500;
        }
        else{
            rent=1200;
        }
    }
    if(currentLocation.name=="MOTOR BOAT"){
        if(brd.location[12].occupied==companyOwner){
            rent=200*dice;
        }
        else{
            rent=100*dice;
        }
    }
    return rent;
    
}
void companyDiscription(board & brd){
    auto currentLocation=brd.location[brd.players[brd.currentplayer].currentlocation];
    if(currentLocation.occupied!=-1)return;
    if(currentLocation.name=="WATER WORKS"){
        cout<<"RENT:Rs.500/- ."<<endl;
        cout<<"If you own AIR INDIA the rent is Rs.100/- ."<<endl;
    }
    if(currentLocation.name=="RAILWAYS"){
        cout<<"RENT:Rs.1000/- ."<<endl;
        cout<<"If you own AIR INDIA the rent is Rs.1350/- ."<<endl;
    }
    if(currentLocation.name=="ELECTRIC COMPANY"){
        cout<<"RENT:50 times dice value ."<<endl;
        cout<<"If you also own MOTOR BOAT rent is 100 times dice value ."<<endl;
    }
    if(currentLocation.name=="BEST"){
        cout<<"RENT:Rs.600/- ."<<endl;
        cout<<"If you own RAILWAYS the rent is Rs.110/- ."<<endl;
    }
    if(currentLocation.name=="AIR INDIA"){
       cout<<"RENT:Rs.1200/- ."<<endl;
        cout<<"If you own WATER WORKS the rent is Rs.1500/- ."<<endl;
    }
    if(currentLocation.name=="MOTOR BOAT"){
       cout<<"RENT:100 times dice value ."<<endl;
        cout<<"If you also own ELECTRIC COMPANY rent is 200 times dice value ."<<endl;
    }
}
void precompute(){
    setnames();
    setcost();
    setrent();
    setbuiltcost();
}

void communityChest(int dice,board& brd){
    if(dice==2){
        cout<<"It is "<<brd.players[brd.currentplayer].name<<"'s Birthday collected from each player Rs.500/- ."<<endl;
        for(int i=0;i<brd.numberofplayers;i++){
            brd.players[i].cash-=500;
        }
        brd.players[brd.currentplayer].cash+=1000;
    }
    if(dice==3){
        cout<<brd.players[brd.currentplayer].name<<" please go to JAIL ."<<endl;
        brd.players[brd.currentplayer].currentlocation=9;
    }
    if(dice==4){
        cout<<brd.players[brd.currentplayer].name<<" won Rs. 2500/- in reality TV show ."<<endl;
        brd.players[brd.currentplayer].cash+=2500;
    }
    if(dice==5){
        cout<<brd.players[brd.currentplayer].name<<" please pay School and Meducal fees of Rs. 1000 /-"<<endl;
        brd.players[brd.currentplayer].cash-=1000;
    }
    if(dice==6){
        cout<<brd.players[brd.currentplayer].name<<" got INCOME TAX refund of Rs. 2000/- ."<<endl;
        brd.players[brd.currentplayer].cash+=2000;
    }
    if(dice==7){
        cout<<brd.players[brd.currentplayer].name<<" please pay Marrige celebration cost of Rs. 2000 /-"<<endl;
        brd.players[brd.currentplayer].cash-=2000;
    }
    if(dice==8){
        cout<<brd.players[brd.currentplayer].name<<" please go to rest you will not play next turn (+ Rs. 50/-) ."<<endl;
        brd.players[brd.currentplayer].currentlocation=27;
        brd.players[brd.currentplayer].stop=1;
    }
    if(dice==9){
        cout<<brd.players[brd.currentplayer].name<<" please pay School and Meducal fees of Rs. 1000 /-"<<endl;
        brd.players[brd.currentplayer].cash-=1000;
    }
    if(dice==10){
        cout<<brd.players[brd.currentplayer].name<<" Recieve intrest on shares of Rs. 1500/- ."<<endl;
        brd.players[brd.currentplayer].cash+=1500;
    }
    if(dice==11){
        int repaircost=0;
        for(int i=0;i<4;i++){
            int x=brd.players[brd.currentplayer].rentLevel[i];
            if(x==4)repaircost+=400;
            else repaircost+=50*x;            
        }
        cout<<brd.players[brd.currentplayer].name<<" please repair your property Rs. 50/- for each rentLevel and Rs. 100/- for each hotel"<<endl;
        brd.players[brd.currentplayer].cash-=repaircost;
    }
    if(dice==12){
        cout<<brd.players[brd.currentplayer].name<<" sale his stoks worth of Rs. 3000/- ."<<endl;
        brd.players[brd.currentplayer].cash+=3000;
    }

}

void CHANCE(int dice,board &brd){
    if(dice==2){
        cout<<brd.players[brd.currentplayer].name<<" loss Rs. 2000 /- in share market ."<<endl;
        brd.players[brd.currentplayer].cash-=2000;
    }
    if(dice==3){
        cout<<brd.players[brd.currentplayer].name<<" won Lottery of Rs. 2500/- ."<<endl;
        brd.players[brd.currentplayer].cash+=2500;
    }
    if(dice==4){
        cout<<brd.players[brd.currentplayer].name<<" have to pay Drink and Drive fine of Rs. 1000 /- ."<<endl;
        brd.players[brd.currentplayer].cash-=1000;
    }
    if(dice==5){
        cout<<brd.players[brd.currentplayer].name<<" won  Rs. 1000/- in crossword compitition ."<<endl;
        brd.players[brd.currentplayer].cash+=1000;
    }
    if(dice==6){
        cout<<brd.players[brd.currentplayer].name<<" please pay House repair cost of Rs. 1500 /- ."<<endl;
        brd.players[brd.currentplayer].cash-=1500;
    }
    if(dice==7){
        cout<<brd.players[brd.currentplayer].name<<" won a Jack Pot of Rs. 2000/- ."<<endl;
        brd.players[brd.currentplayer].cash+=2000;
    }
    if(dice==8){
        cout<<brd.players[brd.currentplayer].name<<" has loss due to fire in godown of Rs. 3000 /- ."<<endl;
        brd.players[brd.currentplayer].cash-=3000;
    }
    if(dice==9){
        cout<<brd.players[brd.currentplayer].name<<" please go to Darjeeling and collect Rs. 1500/- from bank ."<<endl;
        brd.players[brd.currentplayer].currentlocation=23;
        brd.players[brd.currentplayer].cash+=1500;
    }
    if(dice==10){
        cout<<brd.players[brd.currentplayer].name<<" please go to JAIL ."<<endl;
        brd.players[brd.currentplayer].currentlocation=9;
    }
    if(dice==11){
        cout<<brd.players[brd.currentplayer].name<<" won Rs. 3000/- for best Export ."<<endl;
        brd.players[brd.currentplayer].cash+=3000;
    }
    if(dice==12){
        cout<<brd.players[brd.currentplayer].name<<" please go to rest you will not play next turn (+ Rs. 50/-) ."<<endl;
        brd.players[brd.currentplayer].currentlocation=27;
        brd.players[brd.currentplayer].stop=1;
    }
}



signed main(){
    precompute();
    srand(time(0));
    int np;
    cout<<"How many members are playing:";inputint(np,1,5);
    board brd(np);
    int movecount=0;
    while(1){
        system("cls");
        brd.status();
        int turn=movecount%np;
        int dice1,dice2;
        brd.currentplayer=turn;
        if(brd.players[turn].stop>0){
            cout<<brd.players[turn].name<<" please stay in "<<brd.location[brd.players[turn].currentlocation].name<<" ."<<endl;
            brd.players[turn].stop--;movecount++;
            if(!brute)system("pause");
            continue;
        }
        cout<<brd.players[turn].name<<"'s turn:";inputint(dice1,1,6,true);inputint(dice2,1,6,true);
        if(brd.players[turn].currentlocation==9 && (dice1!=dice2)){
            cout<<"An amount of "<<brd.jailPenulty<<" is deducted from "<<brd.players[turn].name<<"'s account as JAIL penalty ."<<endl;
            brd.players[turn].cash-=brd.jailPenulty;
        }
        //MOVE
        brd.playMove(turn,dice1,dice2);
        //Interaction
        if(gameOver)break;
        companyDiscription(brd);
        //Other's Property
        brd.payRent(dice1+dice2);
        brd.interaction();
        movecount++;
        if(!brute)system("pause");
    }
    system("cls");
    for(int i=0;i<np;i++){
        int marcketcapital=(brd.players[i].assets)+(brd.players[i].cash);
        cout<<brd.players[i].name<<" :: $ "<<marcketcapital<<" /-"<<endl;
    }
return 0;
}

