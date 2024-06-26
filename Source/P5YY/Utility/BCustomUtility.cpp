﻿#include "BCustomUtility.h"

#include "Editor.h"
#include "EditorViewportClient.h"
#include "Kismet/KismetMathLibrary.h"


void UBCustomUtility::Test(int a, int b)
{
	
}

FVector UBCustomUtility::GetViewportCamLoc()
{
#if WITH_EDITOR || !WITH_EDITOR
	//FViewport* Viewport = GEditor->GetActiveViewport();
	//FIntPoint mousePos;
	//GEditor->GetActiveViewport()->GetMousePos(mousePos, true);
	FVector viewPos;
	FViewport* activeViewport = GEditor->GetActiveViewport();
	FEditorViewportClient* editorViewClient = (FEditorViewportClient*)activeViewport->GetClient();
	if( editorViewClient )
	{
		viewPos = editorViewClient->GetViewLocation();
	}
	return viewPos;
#endif
	//return FVector(0.0f, 0.0f, 0.0f);
	//return  FVector::Zero();
}

FRotator UBCustomUtility::GetViewportCamRot()
{
#if WITH_EDITOR || !WITH_EDITOR
	FRotator viewRot;
	FViewport* activeViewport = GEditor->GetActiveViewport();
	FEditorViewportClient* editorViewClient = (FEditorViewportClient*)activeViewport->GetClient();
	if( editorViewClient )
	{
		viewRot = editorViewClient->GetViewRotation();
	}
	return viewRot;
#endif
	//return FRotator::ZeroRotator;
}

FVector UBCustomUtility::GetViewportForwardVector(FRotator NewRotator)
{
	return UKismetMathLibrary::GetForwardVector(NewRotator);
}
