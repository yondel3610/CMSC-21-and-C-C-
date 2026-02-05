#include <stdio.h>

int main() {
	while (1){ //while True
		printf("===== MENU =====\n");
		printf("[1] Metric \n");
		printf("[2] Standard \n");
		printf("[3] Exit \n");

		int choice = 0;
		float kg = 0, cm = 0, lb = 0, ft = 0, in = 0; //initialize values
		printf("Please enter your choice: ");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			//metric
			printf("Enter your weight in kilograms(kg): ");
			scanf("%f", &kg);
			printf("Enter your height in centimeters(cm): ");
			scanf("%f", &cm);
			float m = cm/100; //cm to m convertion
			float bmi_metric = kg/(m*m); //bmi formula
			printf("Your BMI is: %f\n", bmi_metric);

			//bmi categories
			if (bmi_metric < 18.5) {
				printf("BMI Category: Underweight\n");
			} else if (18.5 < bmi_metric < 25) { 
				printf("BMI Category: Normal\n");
			} else if (25 < bmi_metric < 30){
				printf("BMI Category: Overweight\n");
			} else if (bmi_metric > 30){
				printf("BMI Category: Obese\n");
			}
			break;

		case 2:
			//standard
			printf("Enter your weight in pounds(lb): ");
			scanf("%f", &lb);
			printf("Enter your height in feet(ft): ");
			scanf("%f", &ft);
			printf("Enter your height in inches(in): ");
			scanf("%f", &in);

			float kg_convert = lb * 0.4535; //convert from lb to kg
			float ft_convert = (ft * 12 + in) * 2.54; //convert ft and in to cm
			float m_convert = ft_convert/100; //cm to m
			float bmi_standard = kg_convert/(m_convert * m_convert); //bmi formula
			printf("Your BMI is: %f\n", bmi_standard);

			//bmi categories
			if (bmi_standard < 18.5) {
				printf("BMI Category: Underweight\n");
			} else if (18.5 < bmi_standard < 25) { 
				printf("BMI Category: Normal\n");
			} else if (25 < bmi_standard < 30){
				printf("BMI Category: Overweight\n");
			} else if (bmi_standard > 30){
				printf("BMI Category: Obese\n");
			}
			break;


		case 3:
			printf("Program terminated. \n");
			break;
		}//switch case
	}//while
    return 0;
}