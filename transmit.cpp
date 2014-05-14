#include "transmit.h"

transmit::transmit()
{

}

bool transmit::changelamp(bool flag, int id, bool status, bool oldstatus){
    char* buffer = new char[4];
    bool tmp;

    if(flag){
        buffer[0] = '?';
    }
    else{
        buffer[0] = '!';
    }

    if(true){
        switch(id+1){
        case 1:
            buffer[1] = '1';
                    break;
        case 2:
            buffer[1] = '2';
                    break;
        case 3:
            buffer[1] = '3';
                    break;
        case 4:
            buffer[1] = '4';
                    break;
        case 5:
            buffer[1] = '5';
                    break;
        case 6:
            buffer[1] = '6';
                    break;
        case 7:
            buffer[1] = '7';
                    break;
        case 8:
            buffer[1] = '8';
                    break;
        case 9:
            buffer[1] = '9';
                    break;
        case 10:
            buffer[1] = 'a';
                    break;
        case 11:
            buffer[1] = 'b';
                    break;
        case 12:
            buffer[1] = 'c';
                    break;
        case 13:
            buffer[1] = 'd';
                    break;
        case 14:
            buffer[1] = 'e';
                    break;
        case 15:
            buffer[1] = 'f';
                    break;
        default:
            break;
        }
    }
    if(status == oldstatus){
        tmp = false;
        return tmp;

    }
    if(status && status != oldstatus){
        buffer[2] = 'f';
        tmp = true;
    }
    if(!status && status != oldstatus){
        buffer[2] = '0';
        tmp = true;
    }
    buffer[3] = char(13);

    if(true){
        CSerial* serial = new CSerial();

        if(!serial->Open(2, 9600))
        {
            qDebug() << "Could not open COM";
        }
        else{
            serial->SendData(buffer, 4);

            serial->Close();
        }
        delete serial;
    }

    qDebug() << buffer[0];
    qDebug() << buffer[1];
    qDebug() << buffer[2];
    qDebug() << buffer[3];
    return tmp;
}

void transmit::checkcalender(enheder *ptrenheder,totalkonfiguration *ptrkonfig){ //funktionen skal startes 1 gang per time
    date = QDate::currentDate();
    bool nystatus;
    for(int i = 0; i < ptrkonfig->konfigurationliste.size(); i++){
        konfiguration tmpkonfig = ptrkonfig->konfigurationliste.at(i);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        if(tmpkonfig.getstatus(ltm->tm_hour-1, date.dayOfWeek()-1)){
            lysenhed tmplys = ptrenheder->lysenheder.at(i);
            if(!tmplys.getmanuelt()){
                nystatus = changelamp(true,tmplys.getID(),true, tmplys.getstatus());
                if(nystatus){
                    tmplys.setstatus(true);
                    ptrenheder->lysenheder.at(i) = tmplys;
                }
            }
        }
        else{
            lysenhed tmplys = ptrenheder->lysenheder.at(i);
            if(!tmplys.getmanuelt()){
                nystatus = changelamp(true,tmplys.getID(),false, tmplys.getstatus());
                if(nystatus){
                    tmplys.setstatus(false);
                    ptrenheder->lysenheder.at(i) = tmplys;
                }
            }
        }

    }
}

void transmit::usemanuelt(enheder* ptrenheder){
    for(int i = 0; i < ptrenheder->lysenheder.size(); i++){

        lysenhed tmplys = ptrenheder->lysenheder.at(i);
        if(tmplys.getmanuelt()){
            changelamp(false, tmplys.getID(), true, tmplys.getstatus());
            tmplys.setstatus(true);
            ptrenheder->lysenheder.at(i) = tmplys;
        }
    }
}


