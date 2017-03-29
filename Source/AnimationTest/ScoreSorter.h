// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ScoreSorter.generated.h"

//Define a Structure
USTRUCT(BlueprintType,Atomic)
struct FPlayerScore
{
	GENERATED_USTRUCT_BODY();

	//String for Name
	UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category="Score")
	FString Name;
	//int for score, annoyingly we can't use uint32 with blueprints
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
};

//Score sorter, actor component so we can add it to any actor
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANIMATIONTEST_API UScoreSorter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreSorter();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Called when we end
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//Add Score function
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(const FPlayerScore &Score);

	///Sort function
	UFUNCTION(BlueprintCallable, Category = "Score")
	void Sort();

	//The TArray which holds all the scores
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ScoreSort")
	TArray<FPlayerScore> CurrentScores;
	
};
