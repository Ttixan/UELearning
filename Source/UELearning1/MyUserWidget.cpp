// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

//UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
//{
//    LoginButton = nullptr;
//    UsernameTextBox = nullptr;
//    PasswordTextBox = nullptr;
//}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (Button_Confirm)
	{
		Button_Confirm->OnClicked.AddDynamic(this, &UMyUserWidget::OnButton_ConfirmClick);
	}
}

void UMyUserWidget::OnButton_ConfirmClick()
{
    // 获取当前编辑框内的文本内容
    //FText UsernameText = TextBox_Username->GetText();
    //FText PasswordText = TextBox_Password->GetText();
    //FString UsernameStr = UsernameText.ToString();
    //FString PasswordStr = PasswordText.ToString();
    ////UE_LOG(LogTemp, Warning, TEXT("%s"), *UsernameStr);
    //if (UsernameStr.Len() <= 0 || PasswordStr.Len() <= 0)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Username or Password must not be empty"));
    //    return;
    //}
    //UE_LOG(LogTemp, Warning, TEXT("Login success"));
}

//void UMyUserWidget::HideWidgets(UWidget* WidgetToHide)
//{
//    if (WidgetToHide)
//    {
//        WidgetToHide->SetVisibility(ESlateVisibility::Hidden); // 隐藏 Widget
//    }
//}
