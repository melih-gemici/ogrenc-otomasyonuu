#include <iostream>
#include <string>
using namespace std;

struct Node { 
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class studentlist {
private:
    Node* head;

public:
    studentlist() {
        head = nullptr;
    }

   void addContact(string name) {
    Node* newNode = new Node(name);

    if (head == nullptr) { 
        // Liste boşsa, yeni düğüm başa eklenir
        head = newNode;
    } else {
        // Liste boş değilse, sona ekle
        Node* tmp = head;
        while (tmp->next != nullptr) { 
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

    

    void displayContacts() {//ogrenci listesi
        if (head == nullptr) {
            cout << "Liste boş, öğrenci bulunamadı." << endl;
            return;
        }

        cout << "sınıf listesi: " << endl;
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name << endl;
            tmp = tmp->next;
        }
    }

    bool searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    ~studentlist() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

struct nNode {//sinava giren ogrencilerin hem adini hem notunu bulunduran node sinifi
    string name;
    int score;
    nNode* next;

    nNode(string n, int s) : name(n), score(s), next(nullptr) {}
};

class LinkedList3 { // isim ve not bulunduran liste
public:
    nNode* head;

    LinkedList3() : head(nullptr) {}

    // Node eklerken, score 100'den küçük olmalı ve aynı isimli öğrenci eklenmemeli
    bool addNode(string name, int score) {
        // Score 100'den büyükse eklemeyin
        if (score > 100 || score < 0) {
            cout << "Not 100 den buyuk veya 0 dan kucuk  olamaz. Lütfen geçerli bir not girin." << endl;
            return false;
        }

        // Aynı isme sahip öğrenci zaten eklenmişse eklemeyin
        nNode* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Bu öğrenci zaten listeye eklenmiş!" << endl;
                return false;
            }
            temp = temp->next;
        }

        // ogrenci ad ve notu ekleme
        nNode* newNode = new nNode(name, score);
        if (!head) {
            head = newNode;
        } else {
            nNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        return true;//dogru
    }

    LinkedList3 filterAbove50() {// 50 uzeri alan ogrencileri filtreleme
        LinkedList3 filteredList; // yeni list adi belirtildi
        
        nNode* temp = head;
        while (temp) {
            if (temp->score > 50) {
                filteredList.addNode(temp->name, temp->score);
            }
           
            
            temp = temp->next;
        }
        return filteredList;
        
    }
LinkedList3 umut(){//50 den az (<) alan ogrencileri filtreleme
    LinkedList3 kalanlar; // kalanlar listesi olusturma
     nNode* temp = head;
        while (temp) {
            if (temp->score < 50) {
                kalanlar.addNode(temp->name, temp->score);
            }
           
            
            temp = temp->next;
        }
        return kalanlar ;
}

    void printList() { // adi ve notu girilmis olan ogrencileri listeleme
        nNode* temp = head;
        while (temp) {
            cout << temp->name << " (" << temp->score << ")" << endl;
            temp = temp->next;
        }
    }
};

int main() {
    studentlist *studentlist1 = new studentlist();
    studentlist1->addContact("kaan");//sinifta bulunan ogrenciler
    studentlist1->addContact("umut");
    studentlist1->addContact("melih");
    studentlist1->addContact("murat");
    studentlist1->addContact("celal");
    studentlist1->addContact("ayse");
    studentlist1->addContact("irem");
    studentlist1->addContact("ada");
    studentlist1->addContact("rana");
    studentlist1->addContact("ahmet");

    // sınıf listesini göster
    studentlist1->displayContacts();

    LinkedList3 list;// tanimlamalar
    int sayi = 0;

    // Öğrencilerin studentlist içinde olup olmadığını kontrol etme
    while (sayi < 10) {//ogrenci sayisi 10 oldugu icin 10 kerelik döngü
        cout << "Öğrenci adı girin: ";
        string name;
        cin >> name; // ad alınıyor

        // studentlist içinde olup olmadığını kontrol et
        if (studentlist1->searchContact(name)) { // eger isim listede varsa iceri girer
            cout << "Öğrenci notu girin: ";
            int score;
            cin >> score; // not girdisi

            // Sadece score 100'den küçükse ve aynı isimli öğrenci daha önce eklenmemişse eklenir
            if (list.addNode(name, score)) {// addNode icerisinde sayi 0 ile 100 arasinda olacak sekilde olusturuldu
                sayi++;  // Sayac sadece geçerli bir öğrenci eklenirse artar
            }
        } else {
            cout << "Öğrenci, listeye eklenemedi çünkü bu öğrenci yok!" << endl;
        }
    }

    cout << "\nSınav notları:" << endl;
    list.printList();// sinav sonucunda isim ve notlari bulunduran liste yazidirilacak

    LinkedList3 above50List = list.filterAbove50();//gecen listesi
    cout << "\nGeçenler:" << endl;
    above50List.printList();
  LinkedList3 umutlist = list.umut();//kalan listesi 
    cout << "\nkalanlar:" << endl;
    umutlist.printList();
  
   

    delete studentlist1;
    return 0;
}