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
4. Paleisti testus:
```
./testai
```

## v1.5

Sioje versijoje prideta bazine (abstrakti) klase `Zmogus` ir is jos isvestine (derived) klase `Studentas`.
Programa islieka veiksni ir naudoja ta pacia v1.2 logika, tik `Studentas` dabar paveldi bendra informacija apie zmogu (varda ir pavarde).

### Klasiu struktura

| Klase | Tipas | Paskirtis | Pastabos |
|------|------|----------|---------|
| `Zmogus` | Abstrakti bazine | Saugo bendra informacija apie zmogu (`vardas_`, `pavarde_`) | Negalima sukurti `Zmogus` objektu, nes turi `virtual std::string tipas() const = 0;` |
| `Studentas` | Isvestine is `Zmogus` | Saugo studento pazymius ir skaiciavimus | Igyvendina `tipas()` ir palaiko v1.2 rule of five |

Bandant sukurti objekta:


### Realizuoti metodai ir operatoriai

| Funkcionalumas              | Realizacija | Kada naudojama                                                              |
|-----------------------------|---|-----------------------------------------------------------------------------|
| Copy konstruktorius         | `Studentas(const Studentas& s)` | Kai sukuriama objekto kopija (pvz. kopijuojant i konteinerius)              |
| Copy assignment operatorius | `Studentas& operator=(const Studentas& s)` | Kai vykdomas priskyrimas `a = b`                                            |
| Move konstruktorius         | `Studentas(Studentas&& s)` | Kai objektas perkeliamas is laikino (pvz. su `std::move`)                   |
| Move assignment operatorius | `Studentas& operator=(Studentas&& s)` | Kai vykdomas `a = std::move(b)`                                             |
| Destruktorius               | `~Studentas()` | Automatiskai kvieciamas iseinant is scope                                   |
| Ivesties operatorius        | `operator>>(std::istream&, Studentas&)` | Skaito eilute formatu `Vardas Pavarde ND... Egz` (tinka failams ir testams) |
| Isvesties operatorius       | `operator<<(std::ostream&, const Studentas&)` | Isveda `Vardas Pavarde ND... Egz` (patogu spausdinimui ir testams)          |

Visi metodai, operatoriai atliekus testavima vis dar veikia teisingai:

<img width="565" height="252" alt="image" src="https://github.com/user-attachments/assets/61c50a74-307b-4a2e-a51f-06d304c95645" />
