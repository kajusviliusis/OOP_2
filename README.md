## Programos aprašymas

Programa skirta apdoroti studentų duomenis ir analizuoti jų akademinius rezultatus. Ji leidžia:

- Įvesti studentų duomenis rankiniu būdu
- Įvesti vardus ir pavardes, o pažymius sugeneruoti atsitiktinai
- Atsitiktinai generuoti studentų vardus, pavardes ir pažymius
- Nuskaityti studentų duomenis iš failo
- Sugeneruoti failą su atsitiktiniais studentų duomenimis

Programoje taip pat įgyvendintos trys strategijos, skirtos palyginti programos veikimo laiką naudojant skirtingus konteinerius (vector, list, deque) skirstant studentus į pažangius ir nepažangius.

## Naudojimosi instrukcijos

Instaliuokite CMake, C++ kompiliatorių.

1. Klonuoti projektą:

```
git clone https://github.com/kajusviliusis/OOP_1.git
cd OOP_1
```
2. Sukurti build directory ir kompiliuoti su CMake:
```
mkdir build
cd build
cmake ..
cmake --build .
```

3. Paleisti programą:
```
./OOP_1
```

## Kompiuterio specifikacijos
- Procesorius: Intel Core i5-12450H, 8 branduoliai
- RAM: 16 GB
- SSD: 512 GB

## v1.1 rezultatai

v1.1 šaka sukurta siekiant palyginti class ir struct naudojimą studentų duomenų saugojimui. Žemiau pateikiami atlikto tyrimo rezultatai. Versijoje v1.1 įgyvendinta class struktūra lyginama su v1.0, kurioje naudotas struct.
Tyrimas atliktas pasitelkiant 3 strategiją ir naudojant vektoriaus konteinerį.

| Programos veikimo laikas su CLASS | Programos veikimo laikas su STRUCT | Studentų kiekis | Optimizavimo vėliava | Vykdomojo failo dydis su CLASS (KB) | Vykdomojo failo dydis su STRUCT (KB) |
| ------ | ----- | --------------- | ------------------------ | ---- | ---- |
| 0.2189s | 0.2070s | 100 000 | -O1 | 149 | 149 |
| 0.2282s | 0.2137s | 100 000 | -O2 | 146 | 153 |
| 0.2261s | 0.2019s | 100 000 | -O3 | 148 | 152 |
| 0.4896s | 0.4138s | 100 000 | - | 234 | 229 |
|  |  |  |  |  |  |
| 1.7954s | 1.9903s | 1 000 000 | -O1 | 149 | 149 |
| 1.7116s | 2.1445s | 1 000 000 | -O2 | 146 | 153 |
| 1.7465s | 2.0847s | 1 000 000 | -O3 | 148 | 152 |
| 4.4061s | 4.4432s | 1 000 000 | - | 234 | 229 |