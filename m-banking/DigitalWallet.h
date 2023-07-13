#ifndef DIGITALWALLET_H
#define DIGITALWALLET_H

class DigitalWallet
{
public:
    DigitalWallet();
    void topUpMenu();
    void topUpOvo();
    void topUpGopay();
    void topUpDana();
    void topUpShopeePay();
    void topUpLinkAja();
    
    //void isExit = false;
    //double getTopUpAmount();
   
    double getTopUpAmount() const;
   

private:
    double topUpAmount;
    double nomorMerchant;
   
};

#endif // DIGITALWALLET_H




   


