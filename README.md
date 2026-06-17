# HydroGrid 🏔️🔋💧

> **English** | **[ქართული](#ქართული-ვერსია)**

**HydroGrid** is an eco-friendly, seasonal, closed-loop green hydrogen energy storage system designed to provide reliable, year-round power to high-altitude off-grid facilities in extreme alpine environments.

---

## 🇺🇸 English Version

### 📌 Overview
Various facilities located in high-altitude regions, such as research stations, meteorological outposts, and ranger cabins, primarily rely on solar energy. However, during the winter, due to severe blizzards, low temperatures, and reduced sunlight, they are often left without electricity. Conventional lithium-ion batteries lose their efficiency at temperatures below 0°C and sometimes fail completely, making the use of diesel generators unavoidable.

Transporting diesel fuel on difficult, icy mountain roads is highly expensive, hazardous, and sometimes completely impossible when roads are closed due to extreme weather conditions. Furthermore, generators are noisy, emit harmful greenhouse gases, and negatively impact the surrounding ecosystem—which is particularly problematic in protected natural zones.

Our project aims to create an eco-friendly and stable energy system for high-altitude facilities that operates reliably year-round. HydroGrid utilizes hydrogen technology to establish a completely closed energy cycle where the only byproduct is pure, distilled water. This system allows us to store excess energy generated during the summer for winter use with virtually zero energy loss, providing a clean, sustainable energy source capable of functioning in even the most extreme environmental conditions.

---

### 🔄 The Closed-Loop Architecture
Unlike typical battery setups or open-ended hydrogen designs, HydroGrid operates on a self-contained, infinite molecular loop:
☀️ Summer (Solar Excess)                     ❄️ Winter (Power Deficit)

Purified Water Reservoir                     Metal-Hydride H₂ Storage
│                                              │
▼                                              ▼
PEM Electrolyzer Stack  ───────────────►       PEM Fuel Cell Stack
(Splits H₂O to H₂)                         (Combines H₂ with Air O₂)
│                                              │
▼                                              ▼
Vents harmless O₂ to air                     Outputs: Electricity + Heat
│
▼
Recovers H₂O back to tank! 🔄
1. **Water Reservoir (H₂O):** The starting and ending point. It supplies purified water to the system during seasonal transitions.
2. **PEM Electrolyzer:** During the summer, excess solar voltage splits water into Hydrogen (H₂) and Oxygen (O₂). The oxygen is safely vented, while hydrogen is routed to storage.
3. **Solid-State Metal-Hydride Storage:** Hydrogen is bound chemically within a solid alloy lattice at low pressures (<30 bar). This completely eliminates cold-weather degradation, leaks, or high-pressure explosive risks.
4. **PEM Fuel Cell:** During winter, hydrogen is combined with ambient oxygen, generating electricity and heat for the cabin.
5. **Condensate Return:** The chemical byproduct of the fuel cell reaction is pure liquid water (H₂O), which is condensed and returned to the water reservoir, closing the loop.

---

### 💻 System Control & Micro-Loop Simulation
The orchestration of this hybrid power topology is managed by a software control layer written in **C++ for microcontrollers**, utilizing a robust **State-Machine** design pattern to transition safely between storage and generation phases.

We have built an interactive web-based visual simulation of the molecular splitting and recombining cycle to demonstrate the closed water loop in real-time.

# HydroGrid 🏔️🔋💧

**HydroGrid** არის ეკოლოგიურად სუფთა, სეზონური, დახურული ციკლის მქონე მწვანე წყალბადის ენერგოსისტემა. იგი შექმნილია მაღალმთიან რეგიონებში მდებარე ავტონომიური ობიექტების სტაბილური, მთელი წლის განმავლობაში ელექტროენერგიითა და სითბოთი უზრუნველყოფისთვის ექსტრემალურ კლიმატურ პირობებში.

---

## 📌 პროექტის მიმოხილვა
მაღალმთიან რეგიონებში მდებარე სხვადასხვა ობიექტები, როგორიც არის კვლევითი სადგურები, მეტეოროლოგიური პუნქტები და რეინჯერთა კაბინები, ძირითადად დამოკიდებულნი არიან მზის ენერგიაზე. თუმცა ზამთარში, ძლიერი ქარბუქების, დაბალი ტემპერატურისა და მზის სინათლის შემცირების გამო, ისინი ხშირად ელექტროენერგიის გარეშე რჩებიან. ჩვეულებრივი ლითიუმის ბატარეები 0°C-ზე დაბალ ტემპერატურაზე ეფექტურობას კარგავენ და ზოგჯერ საერთოდ გამოდიან მწყობრიდან, რის შედეგადაც აუცილებელი ხდება დიზელის გენერატორების გამოყენება.

დიზელის საწვავის ტრანსპორტირება რთულ და მოყინულ მთის გზებზე საკმაოდ ძვირი და სახიფათოა. ზოგჯერ შეუძლებელიც, რადგან ექსტრემალურ პირობებში გზები იკეტება კიდეც. ამასთანავე, გენერატორები ქმნიან ხმაურს, გამოყოფენ მავნე აირებს და უარყოფითად მოქმედებენ გარემოზე, რაც განსაკუთრებით პრობლემურია დაცულ ბუნებრივ ზონებში.

ჩვენი პროექტის მიზანია, მაღალმთიანი ობიექტებისთვის შეიქმნას ეკოლოგიურად სუფთა და სტაბილური ენერგოსისტემა, რომელიც იმუშავებს მთელი წლის განმავლობაში. HydroGrid მუშაობს წყალბადის ტექნოლოგიაზე, რომელიც საშუალებას გვაძლევს, შევქმნათ სრულიად დახურული ენერგეტიკული ციკლი, სადაც ერთადერთი გამონაბოლქვი სუფთა, გამოხდილი წყალია (H₂O) და ზაფხულში გამომუშავებული ჭარბი ენერგია ზამთრისთვის შევინახოთ თითქმის ენერგეტიკული დანაკარგების გარეშე, ეკოლოგიურად სუფთა გზით და ვუზრუნველვყოთ სისტემის ფუნქციონირება ყველაზე ექსტრემალურ პირობებშიც.

---

## 🔄 დახურული ციკლის პრინციპი
ჩვეულებრივი ღია სისტემებისგან განსხვავებით, HydroGrid მუშაობს სრულად იზოლირებულ, უსასრულო მოლეკულურ წრეზე:
☀️ ზაფხული (ჭარბი მზე)                      ❄️ ზამთარი (ენერგიის დეფიციტი)

წყლის რეზერვუარი (H₂O)                      მეტალჰიდრიდული საცავი
│                                              │
▼                                              ▼
PEM ელექტროლიზერი      ───────────────►        PEM საწვავის ელემენტი
(შლის H₂O-ს წყალბადად)                        (აერთებს H₂-სა და ჟანგბადს)
│                                              │
▼                                              ▼
ჟანგბადი (O₂) გარემოში                        გამომუშავება: დენი + სითბო
│
▼
წყალი ბრუნდება ავზში! 🔄
. **წყლის რეზერვუარი (H₂O):** სისტემის საწყისი და ბოლო წერტილი. ის ინახავს წყალს, რომელიც სეზონურად გარდაიქმნება ენერგიის მატარებლად.
2. **PEM ელექტროლიზერი:** ზაფხულში მზის პანელების ჭარბი ელექტროენერგიით შლის წყალს წყალბადად (H₂) და ჟანგბადად (O₂). ჟანგბადი უსაფრთხოდ ნიავდება გარემოში, ხოლო წყალბადი მიემართება საცავისკენ.
3. **მეტალჰიდრიდული საცავი:** წყალბადი ინახება მყარ მდგომარეობაში, სპეციალური ლითონის კრისტალურ სტრუქტურაში, დაბალ წნევაზე (<30 bar). ეს გამორიცხავს ყინვაში ენერგიის კარგვას, გაჟონვას ან აფეთქების რისკს.
4. **PEM საწვავის ელემენტი (Fuel Cell):** ზამთარში, მზის არარსებობისას, იღებს შენახულ წყალბადს, აერთებს მას ჰაერის ჟანგბადთან და გამოიმუშავებს დენსა და სითბოს.
5. **დახურული კონდენსაციის წრედი:** რეაქციის გვერდითი პროდუქტი – წყლის ორთქლი – კონდენსირდება, გადაიქცევა თხევად წყლად და სპეციალური მილებით უკან ბრუნდება საწყის რეზერვუარში შემდეგი წლის ციკლისთვის.

---

## 💻 პროგრამული მართვა და სიმულაცია
ამ ჰიბრიდული სისტემის მუშაობას კოორდინაციას უწევს **C++ ენაზე** დაწერილი მართვის ფენა მიკროკონტროლერებისთვის. ის იყენებს მდგომარეობების აპარატის (**State-Machine**) ალგორითმებს სენსორების მონაცემების დასამუშავებლად და ავარიული გათიშვის (**E-Stop**) უსაფრთხოების რეჟიმების გასააქტიურებლად.

წყლისა და გაზის მოლეკულების დაშლისა და შეერთების პროცესის საილუსტრაციოდ შექმნილია ინტერაქტიული HTML/JS ანიმაცია, რომლის გაშვებაც შესაძლებელია პირდაპირ ბრაუზერში `hydrogrid.html` ფაილის გახსნით.
