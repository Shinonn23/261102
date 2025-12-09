#include <cmath>
#include <gtest/gtest.h>

#define M_PI 3.14159265358979323846

double deg2rad(double a1) { return (a1 * M_PI) / 180.0; }
double rad2deg(double a1) { return (a1 * 180.0) / M_PI; }
double findXComponent(double l1, double l2, double a1, double a2) {
    return l1 * cos(a1) + l2 * cos(a2);
}
double findYComponent(double l1, double l2, double a1, double a2) {
    return l1 * sin(a1) + l2 * sin(a2);
}
double pythagoras(double xcomp, double ycomp) {
    return sqrt(pow(xcomp, 2) + pow(ycomp, 2));
}

class VectorCalculationTest : public ::testing::Test {
  protected:
    const double EPSILON = 1e-4;
};

TEST_F(VectorCalculationTest, Deg2Rad_ZeroDegrees) {
    double result = deg2rad(0);
    EXPECT_NEAR(result, 0.0, EPSILON);
}

TEST_F(VectorCalculationTest, Deg2Rad_90Degrees) {
    double result = deg2rad(90);
    EXPECT_NEAR(result, M_PI / 2, EPSILON);
}

TEST_F(VectorCalculationTest, Deg2Rad_180Degrees) {
    double result = deg2rad(180);
    EXPECT_NEAR(result, M_PI, EPSILON);
}

TEST_F(VectorCalculationTest, Deg2Rad_NegativeDegrees) {
    double result = deg2rad(-45);
    EXPECT_NEAR(result, -M_PI / 4, EPSILON);
}

TEST_F(VectorCalculationTest, Rad2Deg_ZeroRadians) {
    double result = rad2deg(0);
    EXPECT_NEAR(result, 0.0, EPSILON);
}

TEST_F(VectorCalculationTest, Rad2Deg_PiBy2) {
    double result = rad2deg(M_PI / 2);
    EXPECT_NEAR(result, 90.0, EPSILON);
}

TEST_F(VectorCalculationTest, Rad2Deg_Pi) {
    double result = rad2deg(M_PI);
    EXPECT_NEAR(result, 180.0, EPSILON);
}

TEST_F(VectorCalculationTest, Rad2Deg_NegativeRadians) {
    double result = rad2deg(-M_PI / 4);
    EXPECT_NEAR(result, -45.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindXComponent_AlongXAxis) {
    double a1 = deg2rad(0);
    double a2 = deg2rad(0);
    double result = findXComponent(3.0, 4.0, a1, a2);
    EXPECT_NEAR(result, 7.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindXComponent_OppositeDirections) {
    double a1 = deg2rad(0);
    double a2 = deg2rad(180);
    double result = findXComponent(5.0, 2.0, a1, a2);
    EXPECT_NEAR(result, 3.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindXComponent_PerpendicularDirections) {
    double a1 = deg2rad(0);
    double a2 = deg2rad(90);
    double result = findXComponent(3.0, 4.0, a1, a2);
    EXPECT_NEAR(result, 3.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindYComponent_AlongYAxis) {
    double a1 = deg2rad(90);
    double a2 = deg2rad(90);
    double result = findYComponent(3.0, 4.0, a1, a2);
    EXPECT_NEAR(result, 7.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindYComponent_OppositeDirections) {
    double a1 = deg2rad(90);
    double a2 = deg2rad(270);
    double result = findYComponent(5.0, 2.0, a1, a2);
    EXPECT_NEAR(result, 3.0, EPSILON);
}

TEST_F(VectorCalculationTest, FindYComponent_PerpendicularDirections) {
    double a1 = deg2rad(90);
    double a2 = deg2rad(0);
    double result = findYComponent(3.0, 4.0, a1, a2);
    EXPECT_NEAR(result, 3.0, EPSILON);
}

TEST_F(VectorCalculationTest, Pythagoras_3_4_Triangle) {
    double result = pythagoras(3.0, 4.0);
    EXPECT_NEAR(result, 5.0, EPSILON);
}

TEST_F(VectorCalculationTest, Pythagoras_ZeroComponents) {
    double result = pythagoras(0.0, 0.0);
    EXPECT_NEAR(result, 0.0, EPSILON);
}

TEST_F(VectorCalculationTest, Pythagoras_SingleComponent) {
    double result = pythagoras(5.0, 0.0);
    EXPECT_NEAR(result, 5.0, EPSILON);
}

TEST_F(VectorCalculationTest, Pythagoras_LargeValues) {
    double result = pythagoras(100.0, 100.0);
    EXPECT_NEAR(result, 141.4213562, EPSILON);
}

TEST_F(VectorCalculationTest, VectorAddition_Example1) {
    double l1 = 1.0;
    double l2 = 2.5;
    double a1_deg = 0;
    double a2_deg = 102.5;

    double a1 = deg2rad(a1_deg);
    double a2 = deg2rad(a2_deg);

    double xcomp = findXComponent(l1, l2, a1, a2);
    double ycomp = findYComponent(l1, l2, a1, a2);
    double result_length = pythagoras(xcomp, ycomp);
    double result_direction = rad2deg(atan2(ycomp, xcomp));

    EXPECT_NEAR(result_length, 2.48351, EPSILON);
    EXPECT_NEAR(result_direction, 79.3517, EPSILON);
}

TEST_F(VectorCalculationTest, VectorAddition_Example2) {
    double l1 = 12.7;
    double l2 = 4.5;
    double a1_deg = -45;
    double a2_deg = 30;

    double a1 = deg2rad(a1_deg);
    double a2 = deg2rad(a2_deg);

    double xcomp = findXComponent(l1, l2, a1, a2);
    double ycomp = findYComponent(l1, l2, a1, a2);
    double result_length = pythagoras(xcomp, ycomp);
    double result_direction = rad2deg(atan2(ycomp, xcomp));

    EXPECT_NEAR(result_length, 14.5301, EPSILON);
    EXPECT_NEAR(result_direction, -27.5935, EPSILON);
}

TEST_F(VectorCalculationTest, VectorAddition_SameDirection) {
    double l1 = 3.0;
    double l2 = 4.0;
    double a1 = deg2rad(45);
    double a2 = deg2rad(45);

    double xcomp = findXComponent(l1, l2, a1, a2);
    double ycomp = findYComponent(l1, l2, a1, a2);
    double result_length = pythagoras(xcomp, ycomp);

    EXPECT_NEAR(result_length, 7.0, EPSILON);
}

TEST_F(VectorCalculationTest, VectorAddition_OppositeDirection) {
    double l1 = 5.0;
    double l2 = 5.0;
    double a1 = deg2rad(0);
    double a2 = deg2rad(180);

    double xcomp = findXComponent(l1, l2, a1, a2);
    double ycomp = findYComponent(l1, l2, a1, a2);
    double result_length = pythagoras(xcomp, ycomp);

    EXPECT_NEAR(result_length, 0.0, EPSILON);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
