// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"          // 使用按钮控件 api
#include "Components/EditableTextBox.h" // 使用可编辑文本框 api
#include "MyUserWidget.generated.h"




/**
 * 
 */
//class UEditableTextBox;
//class UButton;
//class UWidgetAnimation;


UCLASS()
class UELEARNING1_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	// 必须先有控件，再声明变量，名称要保持一致（强绑定）
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* TextBox_Username;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* TextBox_Password;
	// 直接声明即可，无需预先创建（弱绑定）
	//UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	//UEditableTextBox* TextBlock_Optional;
	// 预先创建，再绑定动画，同样名称要保持一致
	//UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	//UWidgetAnimation* Anim_0;
	//// 无需预先创建，绑定动画
	//UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnimOptional))
	//UWidgetAnimation* Anim_1;
	//
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Button_Confirm;

	////// 实际实现中会调用蓝图中的OnInitilized函数
	virtual void NativeConstruct();
	////// 响应函数
	UFUNCTION()
	void OnButton_ConfirmClick();

	//void HideWidgets(UWidget* WidgetToHide);
};
