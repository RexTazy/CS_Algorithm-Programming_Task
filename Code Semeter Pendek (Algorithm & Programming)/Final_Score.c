#include <stdio.h>

int main() {
    float assignment_score, mid_exam_score, final_exam_score, final_score;
    
    printf("Enter Assignment Score: ");
    scanf("%f", &assignment_score);
    
    printf("Enter Mid Exam Score: ");
    scanf("%f", &mid_exam_score);
    
    printf("Enter Final Exam Score: ");
    scanf("%f", &final_exam_score);
    
    final_score = (0.20 * assignment_score) + (0.30 * mid_exam_score) + (0.50 * final_exam_score);
    
    printf("\nFinal Score = %.2f\n", final_score);
    
    return 0;
}