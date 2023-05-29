class ParkingSystem {
public:
    int Big,Small,Medium;
    ParkingSystem(int big, int medium, int small) {
        Big=big;
        Medium=medium;
        Small=small;
    }
    
    bool addCar(int carType) {
        if((carType==1 && Big==0) || (carType==2 && Medium==0) || (carType==3 && Small==0))
            return false;
        else if(carType==1)
            Big--;
        else if(carType==2)
            Medium--;
        else if(carType==3)
            Small--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */