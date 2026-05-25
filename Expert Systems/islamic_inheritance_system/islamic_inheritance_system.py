# !pip install experta
# !sed -i 's/collections.Mapping/collections.abc.Mapping/' /usr/local/lib/python3.*/dist-packages/frozendict/__init__.py

from experta import *

# قاعدة المعرفة - نظام توزيع الحصص
Inheritance_distribution_system = {
    3.1: "Wife gets 1/8, Father gets 1/6, the rest is equally distributed to sons",
    3.2: "Wife gets 1/8, Mother gets 1/6, the rest is equally distributed to sons",
    3.3: "Wife gets 1/8, Father gets 1/6, Mother gets 1/6, the rest is equally distributed to sons",
    3.4: "Wife gets 1/8, the rest is equally distributed to sons",
    4.3: "Wife gets 1/8, Girl gets 1/2, Father gets 1/6, the rest",
    4.4: "Wife gets 1/8, Girl gets 1/2, Mother gets 1/6",
    4.5: "Wife gets 1/8, Girl gets 1/2, Mother gets 1/6, Father gets 1/6, the rest",
    4.6: "Wife gets 1/8, Girl gets 1/2",
    4.7: "Wife gets 1/8, Girls get 2/3, Father gets 1/6, the rest",
    4.8: "Wife gets 1/8, Girls get 2/3, Mother gets 1/6",
    4.9: "Wife gets 1/8, Girls get 2/3, Mother gets 1/6, Father gets 1/6, the rest",
    4.10: "Wife gets 1/8, Girls get 2/3",
    5.1: "Wife gets 1/8, Father gets 1/6, the rest is distributed (male gets double female)",
    5.2: "Wife gets 1/8, Mother gets 1/6, the rest is distributed (male gets double female)",
    5.3: "Wife gets 1/8, Father gets 1/6, Mother gets 1/6, the rest is distributed (male gets double female)",
    5.4: "Wife gets 1/8, the rest is distributed (male gets double female)",
    7.1: "Father gets 1/6, the rest is distributed to sons",
    7.2: "Mother gets 1/6, the rest is distributed to sons",
    7.3: "Father gets 1/6, Mother gets 1/6, the rest is distributed to sons",
    7.4: "All to sons",
    8.3: "Girl gets 1/2, Father gets 1/6, the rest",
    8.4: "Girl gets 1/2, Mother gets 1/6",
    8.5: "Girl gets 1/2, Mother gets 1/6, Father gets 1/6, the rest",
    8.6: "Girl gets 1/2",
    8.8: "Girls get 2/3, Father gets 1/6, the rest",
    8.9: "Girls get 2/3, Mother gets 1/6",
    8.10: "Girls get 2/3, Mother gets 1/6, Father gets 1/6, the rest",
    8.11: "Girls get 2/3",
    9.1: "Father gets 1/6, remainder (male gets double female)",
    9.2: "Mother gets 1/6, remainder (male gets double female)",
    9.3: "Father gets 1/6, Mother gets 1/6, remainder (male gets double female)",
    9.4: "Remainder (male gets double female)",
    12.1: "Husband gets 1/4, Father gets 1/6, the rest to sons",
    12.2: "Husband gets 1/4, Mother gets 1/6, the rest to sons",
    12.3: "Husband gets 1/4, Father gets 1/6, Mother gets 1/6, the rest to sons",
    12.4: "Husband gets 1/4, the rest to sons",
    13.3: "Husband gets 1/4, Girl gets 1/2, Father gets 1/6, the rest",
    13.4: "Husband gets 1/4, Girl gets 1/2, Mother gets 1/6",
    13.5: "Husband gets 1/4, Girl gets 1/2, Mother gets 1/6, Father gets 1/6, the rest",
    13.6: "Husband gets 1/4, Girl gets 1/2",
    13.7: "Husband gets 1/4, Girls get 2/3, Father gets 1/6, the rest",
    13.8: "Husband gets 1/4, Girls get 2/3, Mother gets 1/6",
    13.9: "Husband gets 1/4, Girls get 2/3, Mother gets 1/6, Father gets 1/6, the rest",
    13.10: "Husband gets 1/4, Girls get 2/3",
    14.1: "Husband gets 1/4, Father gets 1/6, remainder (male gets double female)",
    14.2: "Husband gets 1/4, Mother gets 1/6, remainder (male gets double female)",
    14.3: "Husband gets 1/4, Mother gets 1/6, Father gets 1/6, remainder (male gets double female)",
    14.4: "Husband gets 1/4, remainder (male gets double female)",
    15.1: "Husband gets 1/2, Father inherits remainder",
    15.2: "Husband gets 1/2, Mother gets 1/3 of remainder",
    15.3: "Husband gets 1/2, Mother gets 1/3 of remainder, Father inherits rest",
    15.4: "Husband gets 1/2",
    16.1: "Wife gets 1/4, Father inherits remainder",
    16.2: "Wife gets 1/4, Mother gets 1/3 of remainder",
    16.3: "Wife gets 1/4, Mother gets 1/3 of remainder, Father inherits rest",
    16.4: "Wife gets 1/4",
    17.1: "Father inherits all",
    17.2: "Mother gets 1/3",
    17.3: "Mother gets 1/3, Father inherits rest",
    17.4: "Error – system update needed"
}

class Diagnosis_of_the_dead(KnowledgeEngine):
    def __init__(self):
        super().__init__()
        self.disease_scores = {k: 0 for k in Inheritance_distribution_system.keys()}
        self.phrases = None  # سيتم تعبئته من الحقائق

    @DefFacts()
    def initial_facts(self):
        yield Fact(action='start')
        yield Fact(
            phrases=Fact(
                deceased_gender_q="What is the gender of the deceased? ",
                is_he_married_q="Is he married? ",
                is_she_married_q="Is she married? ",
                has_wife_q="Is there a wife for the deceased? ",
                has_husband_q="Is there a husband for the deceased? ",
                has_sons_q="Are there sons for the deceased? ",
                has_father_or_mother_q="Is there a father or a mother of the deceased alive? ",
                how_many_girls_q="How many girls? ",
                parent_alive_q="Is there a father or a mother alive? ",
                girl_count_q="How many girls? "
            )
        )

    def get_phrases(self):
        for fact in self.facts.values():
            if isinstance(fact, Fact) and 'phrases' in fact:
                return fact['phrases']
        return None

    def show_welcome(self):
        print("\n" + "="*50)
        print("Welcome to the Inheritance Distribution System")
        print("="*50 + "\n")

    @Rule(Fact(action='start'), salience=1100)
    def start_session(self):
        self.show_welcome()
        phrases = self.get_phrases()
        if phrases:
            self.phrases = phrases

    #############################################################################
    # قسم الأسئلة العامة والجنس
    #############################################################################
    @Rule(NOT(Fact(deceased_gender=W())), salience=1000)  # rule0
    def ask_deceased_gender(self):
        if self.phrases:
            res = input(self.phrases['deceased_gender_q'] + "( male / female ): ")
            self.declare(Fact(deceased_gender=res.lower().strip()))

    #############################################################################
    # مسار المتوفى: أنثى (Female Path)
    #############################################################################
    @Rule(Fact(deceased_gender='female'), NOT(Fact(is_she_married=W()))) # rule0.2
    def ask_is_she_married(self):
        if self.phrases:
            res = input("\n" + self.phrases['is_she_married_q'] + "( yes / no ): ")
            self.declare(Fact(is_she_married=res.lower().strip()))

    # أنثى غير متزوجة
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='no'), NOT(Fact(parent_alives=W())))  # rule17
    def ask_if_parent_alives(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='no'), Fact(parent_alives='father only'))  # rule17.1
    def results_father_only(self):  
        print(Inheritance_distribution_system[17.1])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='no'), Fact(parent_alives='mother only'))  # rule17.2
    def results_Mother_only(self):  
        print(Inheritance_distribution_system[17.2])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='no'), Fact(parent_alives='both parents alive'))  # rule17.3
    def results_Both_parents_alive(self):  
        print(Inheritance_distribution_system[17.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='no'), Fact(parent_alives='neither'))  # rule17.4
    def results_Neither(self):  
        print(Inheritance_distribution_system[17.4])

    # أنثى متزوجة
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), NOT(Fact(has_husband2=W())))  # rule10
    def ask_if_has_husband2(self):  
        if self.phrases:
            res = input("\n" + self.phrases['has_husband_q'] + "( yes / no ): ")
            self.declare(Fact(has_husband2=res.lower().strip()))

    # أنثى متزوجة وليس لها زوج حي (توفي قبلها مثلاً)
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), NOT(Fact(has_she_sons2=W())))  # rule6
    def ask_if_has_she_sons2(self):  
        if self.phrases:
            res = input("\n" + self.phrases['has_sons_q'] + "(مثلاً: boy and girls / girls only / boy only / none): ")
            self.declare(Fact(has_she_sons2=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='none'), NOT(Fact(parent_alives7=W())))  # rule17
    def ask_if_parent_alives7(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives7=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='none'), Fact(parent_alives7='father only'))  # rule17.1
    def results_father_only6(self):  
        print(Inheritance_distribution_system[17.1])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='none'), Fact(parent_alives7='mother only'))  # تم تصحيح حالة الأحرف m
    def results_Mother_only6(self):  
        print(Inheritance_distribution_system[17.2])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='none'), Fact(parent_alives7='both parents alive'))  # rule17.3
    def results_Both_parents_alive6(self):  
        print(Inheritance_distribution_system[17.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='none'), Fact(parent_alives7='neither'))  # rule17.4
    def results_Neither6(self):  
        print(Inheritance_distribution_system[17.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy only'), NOT(Fact(parent_alives8=W())))  # rule7
    def ask_if_parent_alives8(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives8=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy only'), Fact(parent_alives8='father only'))  # rule7.1
    def results_father_only7(self):  
        print(Inheritance_distribution_system[7.1])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy only'), Fact(parent_alives8='mother only'))  # تم تصحيح حالة الأحرف m
    def results_Mother_only7(self):  
        print(Inheritance_distribution_system[7.2])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy only'), Fact(parent_alives8='both parents alive'))  # rule7.3
    def results_Both_parents_alive7(self):  
        print(Inheritance_distribution_system[7.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy only'), Fact(parent_alives8='neither'))  # rule7.4
    def results_Neither7(self):  
        print(Inheritance_distribution_system[7.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), NOT(Fact(she_how_many_girls2=W()))) # rule8
    def ask_hshe_how_many_girls2(self):
        if self.phrases:
            res = input(self.phrases['how_many_girls_q'] + " (مثلاً: more / one): ")
            self.declare(Fact(she_how_many_girls2=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='one'), NOT(Fact(parent_alives9=W()))) # rule8.1
    def ask_parent_alives9(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_alives9=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='one'), Fact(parent_alives9='father only')) # rule8.3
    def results_father_only8(self):
        print(Inheritance_distribution_system[8.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='one'), Fact(parent_alives9='mother only')) # rule8.4
    def results_mother_only8(self):
        print(Inheritance_distribution_system[8.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='one'), Fact(parent_alives9='both parents alive')) # rule8.5
    def results_both_parents_alive8(self):
        print(Inheritance_distribution_system[8.5])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='one'), Fact(parent_alives9='neither')) # rule8.6
    def results_neither8(self):
        print(Inheritance_distribution_system[8.5])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='more'), NOT(Fact(parent_alives10=W()))) # rule8.7
    def ask_parent_alives10(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_alives10=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='more'), Fact(parent_alives10='father only')) # rule8.8
    def results_father_only9(self):
        print(Inheritance_distribution_system[8.8])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='more'), Fact(parent_alives10='mother only')) # rule8.9
    def results_mother_only9(self):
        print(Inheritance_distribution_system[8.9])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='more'), Fact(parent_alives10='both parents alive')) # rule8.10
    def results_both_parents_alive9(self):
        print(Inheritance_distribution_system[8.10])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='girls only'), Fact(she_how_many_girls2='more'), Fact(parent_alives10='neither')) # rule8.11
    def results_neither9(self):
        print(Inheritance_distribution_system[8.11])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy and girls'), NOT(Fact(parent_alives11=W())))  # rule9
    def ask_if_parent_alives11(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives11=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy and girls'), Fact(parent_alives11='father only'))  # rule9.1
    def results_father_only10(self):  
        print(Inheritance_distribution_system[9.1])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy and girls'), Fact(parent_alives11='mother only'))  # تم تصحيح m
    def results_Mother_only10(self):  
        print(Inheritance_distribution_system[9.2])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy and girls'), Fact(parent_alives11='both parents alive'))  # rule9.3
    def results_Both_parents_alive10(self):  
        print(Inheritance_distribution_system[9.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='no'), Fact(has_she_sons2='boy and girls'), Fact(parent_alives11='neither'))  # rule9.4
    def results_Neither10(self):  
        print(Inheritance_distribution_system[9.4])

    # أنثى متزوجة ولديها زوج حي
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), NOT(Fact(has_she_sons=W())))  # rule11
    def ask_if_has_she_sons(self):  
        if self.phrases:
            res = input("\n" + self.phrases['has_sons_q'] + "(مثلاً: boy and girls / girls only / boy only / none): ")
            self.declare(Fact(has_she_sons=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='none'), NOT(Fact(parent_alives2=W())))  # rule15
    def ask_if_parent_alives2(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives2=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='none'), Fact(parent_alives2='father only'))  # rule15.1
    def results_father_only1(self):  
        print(Inheritance_distribution_system[15.1])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='none'), Fact(parent_alives2='mother only'))  # rule15.2
    def results_mother_only1(self):  
        print(Inheritance_distribution_system[15.2])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='none'), Fact(parent_alives2='both parents alive'))  # rule15.3
    def results_both_parents_alive1(self):  
        print(Inheritance_distribution_system[15.3])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='none'), Fact(parent_alives2='neither'))  # rule15.4
    def results_neither1(self):  
        print(Inheritance_distribution_system[15.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy only'), NOT(Fact(parent_alives3=W())))  # rule12
    def ask_if_parent_alives3(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives3=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy only'), Fact(parent_alives3='father only'))  # rule12.1
    def results_father_only2(self):  
        print(Inheritance_distribution_system[12.1])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy only'), Fact(parent_alives3='mother only'))  # rule12.2
    def results_mother_only2(self):  
        print(Inheritance_distribution_system[12.2])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy only'), Fact(parent_alives3='both parents alive'))  # rule12.3
    def results_both_parents_alive2(self):  
        print(Inheritance_distribution_system[12.3])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy only'), Fact(parent_alives3='neither'))  # rule12.4
    def results_neither2(self):  
        print(Inheritance_distribution_system[12.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), NOT(Fact(she_how_many_girls=W())))  # rule13
    def ask_if_she_how_many_girls(self):  
        if self.phrases:
            res = input("\n" + self.phrases['how_many_girls_q'] + "(مثلاً: more / one): ")
            self.declare(Fact(she_how_many_girls=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='one'), NOT(Fact(parent_alives4=W()))) # rule13.1
    def ask_parent_alives4(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_alives4=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='one'), Fact(parent_alives4='father only')) # Rule 13.3
    def results_father_only3(self):
        print(Inheritance_distribution_system[13.3])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='one'), Fact(parent_alives4='mother only')) # Rule 13.4
    def results_mother_only3(self):
        print(Inheritance_distribution_system[13.4])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='one'), Fact(parent_alives4='both parents alive')) # Rule 13.5
    def results_both_parents_alive3(self):
        print(Inheritance_distribution_system[13.5])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='one'), Fact(parent_alives4='neither')) # Rule 13.6
    def results_neither3(self):
        print(Inheritance_distribution_system[13.5])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='more'), NOT(Fact(parent_alives5=W()))) # rule13.2
    def ask_parent_alives5(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_alives5=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='more'), Fact(parent_alives5='father only')) # Rule 13.7
    def results_father_only4(self):
        print(Inheritance_distribution_system[13.7])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='more'), Fact(parent_alives5='mother only')) # Rule 13.8
    def results_mother_only4(self):
        print(Inheritance_distribution_system[13.8])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='more'), Fact(parent_alives5='both parents alive')) # Rule 13.9
    def results_both_parents_alive4(self):
        print(Inheritance_distribution_system[13.9])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='girls only'), Fact(she_how_many_girls='more'), Fact(parent_alives5='neither')) # Rule 13.10
    def results_neither4(self):
        print(Inheritance_distribution_system[13.10])

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy and girls'), NOT(Fact(parent_alives6=W())))  # rule14
    def ask_if_parent_alives6(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alives6=res.lower().strip()))

    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy and girls'), Fact(parent_alives6='father only'))  # rule14.1
    def results_father_only5(self):  
        print(Inheritance_distribution_system[14.1])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy and girls'), Fact(parent_alives6='mother only'))  # rule14.2
    def results_mother_only5(self):  
        print(Inheritance_distribution_system[14.2])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy and girls'), Fact(parent_alives6='both parents alive'))  # rule14.3
    def results_both_parents_alive5(self):  
        print(Inheritance_distribution_system[14.3])
    @Rule(Fact(deceased_gender='female'), Fact(is_she_married='yes'), Fact(has_husband2='yes'), Fact(has_she_sons='boy and girls'), Fact(parent_alives6='neither'))  # rule14.4
    def results_neither5(self):  
        print(Inheritance_distribution_system[14.4])

    #############################################################################
    # مسار المتوفى: ذكر (Male Path)
    #############################################################################
    @Rule(Fact(deceased_gender='male'), NOT(Fact(is_he_married=W())), salience=900) # rule0.1
    def ask_is_he_married(self):
        if self.phrases:
            res = input("\n" + self.phrases['is_he_married_q'] + "( yes / no ): ")
            self.declare(Fact(is_he_married=res.lower().strip()))

    # ذكر غير متزوج
    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='no'), NOT(Fact(parent_alive=W())), salience=800)  # rule17
    def ask_if_parent_alive(self):  
        if self.phrases:
            res = input("\n" + self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alive=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='no'), Fact(parent_alive='father only'))  # rule17.1
    def result_father_only(self):  
        print(Inheritance_distribution_system[17.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='no'), Fact(parent_alive='mother only'))  # rule17.2
    def result_Mother_only(self):  
        print(Inheritance_distribution_system[17.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='no'), Fact(parent_alive='both parents alive'))  # rule17.3
    def result_Both_parents_alive(self):  
        print(Inheritance_distribution_system[17.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='no'), Fact(parent_alive='neither'))  # rule17.4
    def result_Neither(self):  
        print(Inheritance_distribution_system[17.4])

    # ذكر متزوج
    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), NOT(Fact(has_wife=W()))) # rule1
    def ask_has_wife(self):
        if self.phrases:
            res = input(self.phrases['has_wife_q'] + "( yes / no ): ")
            self.declare(Fact(has_wife=res.lower().strip()))

    # ذكر متزوج وليس له زوجة حية
    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), NOT(Fact(has_sons2=W()))) # rule6
    def ask_has_sons2(self):
        if self.phrases:
            res = input(self.phrases['has_sons_q'] + "(مثلاً: boy and girls / girls only / boy only / none): ")
            self.declare(Fact(has_sons2=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='none'), NOT(Fact(parent_alive1=W()))) # rule17
    def ask_parent_alive1(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alive1=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='none'), Fact(parent_alive1='father only'))  # rule17.1
    def result_father_only1(self):  
        print(Inheritance_distribution_system[17.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='none'), Fact(parent_alive1='mother only'))  # تم تصحيح m
    def result_Mother_only1(self):  
        print(Inheritance_distribution_system[17.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='none'), Fact(parent_alive1='both parents alive'))  # rule17.3
    def result_Both_parents_alive1(self):  
        print(Inheritance_distribution_system[17.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='none'), Fact(parent_alive1='neither'))  # rule17.4
    def result_Neither1(self):  
        print(Inheritance_distribution_system[17.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy only'), NOT(Fact(parent_alive6=W()))) # rule7
    def ask_parent_alive6(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alive6=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy only'), Fact(parent_alive6='father only'))  # rule7.1
    def result_father_only7(self):  
        print(Inheritance_distribution_system[7.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy only'), Fact(parent_alive6='mother only'))  # تم تصحيح m
    def result_Mother_only7(self):  
        print(Inheritance_distribution_system[7.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy only'), Fact(parent_alive6='both parents alive'))  # rule7.3
    def result_Both_parents_alive7(self):  
        print(Inheritance_distribution_system[7.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy only'), Fact(parent_alive6='neither'))  # rule7.4
    def result_Neither7(self):  
        print(Inheritance_distribution_system[7.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), NOT(Fact(how_many_girls21=W()))) # rule8
    def ask_how_many_girls21(self):
        if self.phrases:
            res = input(self.phrases['how_many_girls_q'] + "(مثلاً: more / one): ")
            self.declare(Fact(how_many_girls21=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='one'), NOT(Fact(parent_aliveaa=W()))) # rule8.1
    def ask_parent_aliveaa(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_aliveaa=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='one'), Fact(parent_aliveaa='father only')) # rule8.3
    def result_father_only41(self):
        print(Inheritance_distribution_system[8.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='one'), Fact(parent_aliveaa='mother only')) # rule8.4
    def result_mother_only41(self):
        print(Inheritance_distribution_system[8.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='one'), Fact(parent_aliveaa='both parents alive')) # rule8.5
    def result_both_parents_alive41(self):
        print(Inheritance_distribution_system[8.5])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='one'), Fact(parent_aliveaa='neither')) # تم تصحيح الـ Fact إلى aa
    def result_neither41(self):
        print(Inheritance_distribution_system[8.5])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='more'), NOT(Fact(parent_aliveaaa=W()))) # rule8.7
    def ask_parent_aliveaaa(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_aliveaaa=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='more'), Fact(parent_aliveaaa='father only')) # rule8.8
    def result_father_only411(self):
        print(Inheritance_distribution_system[8.8])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='more'), Fact(parent_aliveaaa='mother only')) # rule8.9
    def result_mother_only411(self):
        print(Inheritance_distribution_system[8.9])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='more'), Fact(parent_aliveaaa='both parents alive')) # rule8.10
    def result_both_parents_alive411(self):
        print(Inheritance_distribution_system[8.10])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='girls only'), Fact(how_many_girls21='more'), Fact(parent_aliveaaa='neither')) # تم تصحيح الـ Fact إلى aaa
    def result_neither411(self):
        print(Inheritance_distribution_system[8.11])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy and girls'), NOT(Fact(parent_alive22=W()))) # rule9
    def ask_parent_alive22(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alive22=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy and girls'), Fact(parent_alive22='father only')) # rule9.1
    def result_father_only61(self):
        print(Inheritance_distribution_system[9.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy and girls'), Fact(parent_alive22='mother only')) # rule9.2
    def result_mother_only61(self):
        print(Inheritance_distribution_system[9.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy and girls'), Fact(parent_alive22='both parents alive')) # rule9.3
    def result_both_parents_alive61(self):
        print(Inheritance_distribution_system[9.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='no'), Fact(has_sons2='boy and girls'), Fact(parent_alive22='neither')) # rule9.4
    def result_neither61(self):
        print(Inheritance_distribution_system[9.4])

    # ذكر متزوج ولديه زوجة حية
    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), NOT(Fact(has_sons1=W()))) # rule2
    def ask_has_sons1(self):
        if self.phrases:
            res = input(self.phrases['has_sons_q'] + "(مثلاً: boy and girls / girls only / boy only / none): ")
            self.declare(Fact(has_sons1=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy and girls'), NOT(Fact(parent_alive2=W()))) # rule5
    def ask_parent_alive2(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alive2=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy and girls'), Fact(parent_alive2='father only')) # rule5.1
    def result_father_only6(self):
        print(Inheritance_distribution_system[5.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy and girls'), Fact(parent_alive2='mother only')) # rule5.2
    def result_mother_only6(self):
        print(Inheritance_distribution_system[5.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy and girls'), Fact(parent_alive2='both parents alive')) # rule5.3
    def result_both_parents_alive6(self):
        print(Inheritance_distribution_system[5.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy and girls'), Fact(parent_alive2='neither')) # rule5.4
    def result_neither6(self):
        print(Inheritance_distribution_system[5.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), NOT(Fact(how_many_girls=W()))) # rule4
    def ask_how_many_girls(self):
        if self.phrases:
            res = input(self.phrases['how_many_girls_q'] + "(مثلاً: more / one): " )
            self.declare(Fact(how_many_girls=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='one'), NOT(Fact(parent_alivea=W()))) # rule4.1
    def ask_parent_alivea(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(parent_alivea=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='one'), Fact(parent_alivea='father only')) # rule4.3
    def result_father_only4(self):
        print(Inheritance_distribution_system[4.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='one'), Fact(parent_alivea='mother only')) # rule4.4
    def result_mother_only4(self):
        print(Inheritance_distribution_system[4.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='one'), Fact(parent_alivea='both parents alive')) # rule4.5
    def result_both_parents_alive4(self):
        print(Inheritance_distribution_system[4.5])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='one'), Fact(parent_alivea='neither')) # rule4.6
    def result_neither4(self):
        print(Inheritance_distribution_system[4.6])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='more'), NOT(Fact(parent_alive5=W()))) # rule4.2
    def ask_parent_alive5(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): " )
            self.declare(Fact(parent_alive5=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='more'), Fact(parent_alive5='father only')) # rule4.7
    def result_father_only5(self):
        print(Inheritance_distribution_system[4.7])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='more'), Fact(parent_alive5='mother only')) # rule4.8
    def result_mother_only5(self):
        print(Inheritance_distribution_system[4.8])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='more'), Fact(parent_alive5='both parents alive')) # rule4.9
    def result_both_parents_alive5(self):
        print(Inheritance_distribution_system[4.9])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='girls only'), Fact(how_many_girls='more'), Fact(parent_alive5='neither')) # rule4.10
    def result_neither5(self):
        print(Inheritance_distribution_system[4.10])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy only'), NOT(Fact(has_father_or_mother2=W()))) # rule3
    def ask_has_father_or_mother2(self):
        if self.phrases:
            res = input(self.phrases['has_father_or_mother_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(has_father_or_mother2=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy only'), Fact(has_father_or_mother2='father only')) # rule3.1
    def result_father_only3(self):
        print(Inheritance_distribution_system[3.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy only'), Fact(has_father_or_mother2='mother only')) # rule3.2
    def result_mother_only3(self):
        print(Inheritance_distribution_system[3.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy only'), Fact(has_father_or_mother2='both parents alive')) # rule3.3
    def result_both_parents_alive3(self):
        print(Inheritance_distribution_system[3.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='boy only'), Fact(has_father_or_mother2='neither')) # rule3.4
    def result_neither3(self):
        print(Inheritance_distribution_system[3.4])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='none'), NOT(Fact(has_father_or_mother=W()))) # rule16
    def ask_has_father_or_mother(self):
        if self.phrases:
            res = input(self.phrases['parent_alive_q'] + " (مثلاً: father only / mother only / both parents alive / neither): ")
            self.declare(Fact(has_father_or_mother=res.lower().strip()))

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='none'), Fact(has_father_or_mother='father only')) # rule16.1
    def result_father_only2(self):
        print(Inheritance_distribution_system[16.1])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='none'), Fact(has_father_or_mother='mother only')) # rule16.2
    def result_mother_only2(self):
        print(Inheritance_distribution_system[16.2])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='none'), Fact(has_father_or_mother='both parents alive')) # rule16.3
    def result_both_parents_alive2(self):
        print(Inheritance_distribution_system[16.3])

    @Rule(Fact(deceased_gender='male'), Fact(is_he_married='yes'), Fact(has_wife='yes'), Fact(has_sons1='none'), Fact(has_father_or_mother='neither')) # rule16.4
    def result_neither2(self):
        print(Inheritance_distribution_system[16.4])


if __name__ == "__main__":
    expert = Diagnosis_of_the_dead()
    expert.reset()
    expert.run()