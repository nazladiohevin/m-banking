# M-Banking 
Command line-based mobile-banking application (CLI) use C++

## DESCRIPTION
Arti setiap class:
- **Main.cpp** -> Menu utama
- **BalanceCheck.cpp** -> Cek Saldo
- **CashWithdrawal.cpp** -> Tarik Tunai
- **Transfer.cpp** -> Transfer
- **CraditData.cpp** -> Pulsa/Data
- **DigitalWallet.cpp** -> Dompet Digital
- **Electricity.cpp** -> Listrik
- **Mutation.cpp** -> Mutasi rekening

- Helper Class berfungsi untuk media pembantu untuk class-class lain. Dimana didalamnya class tersebut
terdapat function-function yang berguna untuk project dan berlaku secara global. Yang artinya bisa diakses di class Manapun. **Dengan catatan**: harus menyertakan **#include "file headernya"** di class yang menggunakannya.
Untuk menambahkan function baru harus pake keyword **static** ya guys. Untuk mengakses function nya tinggal pake kek gini
namaClass::NamaFunction(parameter, parameter...);

### Perhatian!!!
Untuk setiap class memiliki file header yang ber-extensi **.h**. Misal kan untuk file Login.cpp memiliki file header yaitu Login.h. Dimana setiap class memiliki template-nya yang disimpan di file **.h**

Menjalankan semua program di file **Main.cpp**.

JANGAN LUPA INCLUDE FILE .h di Main ketika mau ambil class lain.

### REFERENSI PEMBELAJARAN
Bisa dilihat disini : 
- [W3Schools - Class](https://www.w3schools.com/cpp/cpp_classes.asp)
- [Chat GPT - Class in different file](https://chat.openai.com/share/20a84461-3622-4f32-b6ec-13b3e1bd07eb)