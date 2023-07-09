//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//

#import <Photos/Photos.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface PHAsset (Private)
+ (id) fetchAssetsGroupedByFaceUUIDForFaces:(id)arg1;
+ (id) fetchAssetsForFaces:(id)arg1 options:(id)arg2;
+ (id) fetchAssetsForPerson:(id)arg1 faceCount:(unsigned long)arg2 options:(id)arg3;
+ (id) fetchAssetsForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchAssetsForPersons:(id)arg1 options:(id)arg2;
+ (id) fetchAssetsForReferences:(id)arg1 photoLibrary:(id)arg2;
+ (id) fetchAssetsForSearchLookupIdentifier:(id)arg1 options:(id)arg2;
+ (id) fetchAssetsFromCameraSinceDate:(id)arg1 options:(id)arg2;
+ (id) fetchAssetsGroupedByFaceUUIDForFaces:(id)arg1 fetchPropertySets:(id)arg2;
@property (readonly, nonatomic) struct CGRect faceAreaRect;
@property (readonly, nonatomic) NSArray* faceRegions;
@property (readonly, nonatomic) double faceAreaMinX;
@property (readonly, nonatomic) double faceAreaMaxX;
@property (readonly, nonatomic) double faceAreaMinY;
@property (readonly, nonatomic) double faceAreaMaxY;
@property (readonly, nonatomic) struct CGRect originalFaceAreaRect;
@property (readonly, nonatomic) NSValue* originalFaceAreaRectValue;
@property (readonly, nonatomic) struct CGRect normalizedFaceAreaRect;
- (struct CGRect) faceAreaRect;
- (id) _faceNamesStringForAsset;
@end

@interface PHFace : PHObject
+ (id) px_fetchKeyFaceForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchSuggestedFacesForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchSingletonFacesWithOptions:(id)arg1;
+ (id) _composePropertiesToFetchWithHint:(unsigned long)arg1;
+ (id) analyticsPropertiesToFetch;
+ (id) corePropertiesToFetch;
+ (id) croppingPropertiesToFetch;
+ (id) fetchFacesForFaceCrop:(id)arg1 options:(id)arg2;
+ (id) fetchFacesForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchFacesGroupedByAssetLocalIdentifierForAssets:(id)arg1 options:(id)arg2;
+ (id) fetchFacesInAsset:(id)arg1 options:(id _Nullable)arg2;
+ (id) fetchFacesInAssets:(id)arg1 options:(id)arg2;
+ (id) fetchFacesInFaceGroup:(id)arg1 options:(id)arg2;
+ (id) fetchFacesOnAssetWithFace:(id)arg1 options:(id)arg2;
+ (id) fetchFacesWithLocalIdentifiers:(id)arg1 options:(id _Nullable)arg2;
+ (id) fetchFacesWithOptions:(id)arg1;
+ (id) fetchKeyFaceByPersonLocalIdentifierForPersons:(id)arg1 options:(id)arg2;
+ (id) fetchKeyFaceForFaceGroup:(id)arg1 options:(id)arg2;
+ (id) fetchKeyFaceForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchRejectedFacesForPerson:(id)arg1 options:(id)arg2;
- (BOOL) px_cropRectForPortraitImage:(struct CGRect*)arg1;
- (struct CGRect) px_cropRectWithCropFactor:(double)arg1;
- (struct CGRect) px_cropRectWithCropFactor:(double)arg1 bounded:(BOOL)arg2;
- (struct CGSize) px_faceTileSizeAdjustingForImageAspectRatio:(struct CGSize)arg1;
- (struct CGPoint) px_normalizedCenterEyeLine;
- (id) faceprintData;
- (void) setQualityMeasure:(long)arg1;
- (double) photosFaceRepresentationCenterY;
- (double) photosFaceRepresentationCenterX;
- (double) photosFaceRepresentationQuality;
- (double) photosFaceRepresentationBlurScore;
- (long) photosFaceRepresentationClusterSequenceNumber;
- (BOOL) photosFaceRepresentationHasSmile;
- (BOOL) photosFaceRepresentationIsLeftEyeClosed;
- (BOOL) photosFaceRepresentationIsRightEyeClosed;
- (id) photosFaceRepresentationLocalIdentifier;
- (long) photosFaceRepresentationQualityMeasure;
- (double) photosFaceRepresentationRoll;
- (double) photosFaceRepresentationSize;
- (long) photosFaceRepresentationSourceHeight;
- (long) photosFaceRepresentationSourceWidth;
- (BOOL) vcp_hasBody;
- (BOOL) vcp_hasFace;
- (struct CGRect) vcp_normalizedBodyBounds;
- (struct CGRect) vcp_normalizedFaceBounds;
- (double) quality;
- (BOOL) isHidden;
- (double) size;
- (double) roll;
- (id) adjustmentVersion;
- (BOOL) manual;
- (double) centerX;
- (double) centerY;
- (long) sourceHeight;
- (long) sourceWidth;
- (BOOL) hasSmile;
- (double) poseYaw;
- (unsigned short) ageType;
- (BOOL) isLeftEyeClosed;
- (unsigned short) sexType;
- (id) _createPropertyObjectOfClass:(Class)arg1;
- (id) _createPropertyObjectOfClass:(Class)arg1 preFetchedProperties:(id)arg2;
- (double) blurScore;
- (double) bodyCenterX;
- (double) bodyCenterY;
- (double) bodyHeight;
- (double) bodyWidth;
- (Class) changeRequestClass;
- (long) clusterSequenceNumber;
- (short) confirmedFaceCropGenerationState;
- (short) detectionType;
- (unsigned short) ethnicityType;
- (unsigned short) eyeMakeupType;
- (unsigned short) eyesState;
- (long) faceAlgorithmVersion;
- (id) faceClusteringProperties;
- (unsigned short) faceExpressionType;
- (unsigned short) facialHairType;
- (void) fetchPropertySetsIfNeeded;
- (double) gazeCenterX;
- (double) gazeCenterY;
- (unsigned short) gazeType;
- (unsigned short) glassesType;
- (unsigned short) hairColorType;
- (unsigned short) hairType;
- (BOOL) hasFaceMask;
- (unsigned short) headgearType;
- (id) initWithFetchDictionary:(id)arg1 propertyHint:(unsigned long)arg2 photoLibrary:(id)arg3;
- (BOOL) isConfirmedFaceCropGenerationPending;
- (BOOL) isInTrash;
- (BOOL) isInVIPModel;
- (BOOL) isRightEyeClosed;
- (unsigned short) lipMakeupType;
- (long) nameSource;
- (id) personLocalIdentifier;
- (id) personUUID;
- (unsigned short) poseType;
- (long) qualityMeasure;
- (void) setFaceAlgorithmVersion:(long)arg1;
- (void) setPoseYaw:(double)arg1;
- (unsigned short) skintoneType;
- (unsigned short) smileType;
- (int) trainingType;
@end

@interface PHPerson : PHObject
+ (id) px_fetchPersonsForSuggestion:(id)arg1 options:(id)arg2;
+ (void) px_loadRepresentativeFacesForPersons:(id)arg1;
+ (id) px_localizedNameFromContact:(id)arg1;
+ (id) fetchPredicateFromComparisonPredicate:(id)arg1 options:(id)arg2;
+ (id) propertySetsForPropertyFetchHints:(unsigned long)arg1;
+ (id) fetchType;
+ (id) entityKeyMap;
+ (id) fullNameFromContact:(id)arg1;
+ (unsigned long) propertyFetchHintsForPropertySets:(id)arg1;
+ (id) propertySetAccessorsByPropertySet;
+ (id) displayNameFromContact:(id)arg1;
+ (id) propertiesToFetchWithHint:(unsigned long)arg1;
+ (id) transformValueExpression:(id)arg1 forKeyPath:(id)arg2;
+ (id) identifierCode;
+ (Class) propertySetClassForPropertySet:(id)arg1;
+ (id) managedEntityName;
+ (id) fetchPersonsForContactIdentifiers:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsWithOptions:(id)arg1;
+ (id) fetchPersonForFaceCrop:(id)arg1 options:(id)arg2;
+ (id) fetchPersonCountGroupedByAssetLocalIdentifierForAssets:(id)arg1 options:(id)arg2;
+ (id) _assetLocalIdentifiersForAssetCollection:(id)arg1;
+ (id) _composePropertiesToFetchWithHint:(unsigned long)arg1;
+ (id) _convertToPersonSuggestion:(id)arg1 photoLibrary:(id)arg2;
+ (id) _fetchSuggestedPersonsForClient:(unsigned long)arg1 options:(id)arg2;
+ (id) _fetchSuggestedPersonsForRecipients:(id)arg1 options:(id)arg2 photoLibrary:(id)arg3;
+ (id) _fetchSuggestedRecipientsForFocusedAssetCollection:(id)arg1 assetCollection:(id)arg2 options:(id)arg3 client:(unsigned long)arg4;
+ (id) _momentLocalIdentifiersForAssetCollection:(id)arg1;
+ (id) _packageSuggestionList:(id)arg1 photoLibrary:(id)arg2;
+ (id) _personSuggestionMarkedAsConfirmed:(BOOL)arg1 fromPersonSuggestion:(id)arg2;
//+ (long) _personSuggestionsForPerson:(id)arg1 confirmedPersonSuggestions:(id)arg2 rejectedPersonSuggestions:(id)arg3 fromClient:(id)arg4 completion:(^block)arg5;
+ (id) _requestSuggestedPersonsForClient:(unsigned long)arg1 options:(id)arg2;
+ (id) batchFetchContactInferencesForPersons:(id)arg1 queryOptions:(unsigned long)arg2;
+ (id) batchFetchRelationshipInferencesForPersons:(id)arg1;
+ (id) batchFetchSuggestedRecipientsForAssets:(id)arg1 options:(id)arg2;
+ (id) corePropertiesToFetch;
+ (id) fetchAssociatedPersonsGroupedByFaceGroupLocalIdentifierForFaceGroups:(id)arg1 options:(id)arg2;
+ (id) fetchFinalMergeTargetPersonsForPersonWithUUID:(id)arg1 options:(id)arg2;
+ (id) fetchInvalidMergeCandidatePersonsForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchMergeCandidatePersonsForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchMergeCandidateWithConfidencePersonsForPerson:(id)arg1 options:(id)arg2;
+ (id) fetchPersonAssociatedWithFaceGroup:(id)arg1 options:(id)arg2;
+ (id) fetchPersonForShareParticipant:(id)arg1 options:(id)arg2;
+ (id) fetchPersonUUIDsGroupedByAssetUUIDForAssetUUIDs:(id)arg1 options:(id)arg2;
+ (id) fetchPersonWithFace:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsForAssetCollection:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsForContacts:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsForReferences:(id)arg1 photoLibrary:(id)arg2;
+ (id) fetchPersonsGroupedByAssetLocalIdentifierForAssets:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsInAsset:(id)arg1 options:(id)arg2; 
+ (id) fetchPersonsInAssets:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsWithLocalIdentifiers:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsWithObjectIDs:(id)arg1 options:(id)arg2;
+ (id) fetchPersonsWithQuestionType:(unsigned short)arg1 options:(id)arg2;
+ (id) fetchPersonsWithType:(long)arg1 options:(id)arg2;
+ (id) fetchPersonsWithUserFeedbackWithOptions:(id)arg1;
+ (id) fetchRejectedPersonsForFace:(id)arg1 options:(id)arg2;
+ (id) fetchSuggestedPersonsForAssetCollection:(id)arg1 options:(id)arg2;
+ (id) fetchSuggestedPersonsForClient:(unsigned long)arg1 options:(id)arg2;
+ (id) fetchSuggestedPersonsForFocusedAssetCollection:(id)arg1 options:(id)arg2;
+ (id) fetchSuggestedRecipientsForAssetCollection:(id)arg1 options:(id)arg2;
+ (id) fetchSuggestedRecipientsForFocusedAssetCollection:(id)arg1 options:(id)arg2;
+ (id) fetchVerifiedPersonUUIDsGroupedByAssetUUIDForAssetUUIDs:(id)arg1 options:(id)arg2;
+ (id) identifierPropertiesToFetch;
+ (id) inferredContactByPersonLocalIdentifierForPersons:(id)arg1;
+ (id) localIdentifierExpressionForFetchRequests;
+ (BOOL) managedObjectSupportsDetectionType;
+ (BOOL) managedObjectSupportsKeyFaces;
+ (BOOL) managedObjectSupportsPersonFilters;
+ (BOOL) managedObjectSupportsTorsoOnly;
+ (id) momentCountsByPersonUUIDForPersonsWithUUIDs:(id)arg1 afterDate:(id)arg2 photoLibrary:(id)arg3;
+ (id) personSuggestionsForPerson:(id)arg1 confirmedPersonSuggestions:(id)arg2 rejectedPersonSuggestions:(id)arg3;
//+ (long) personSuggestionsForPerson:(id)arg1 confirmedPersonSuggestions:(id)arg2 rejectedPersonSuggestions:(id)arg3 completion:(^block)arg4;
+ (id) personToKeepForCloudConsistencyFromPersons:(id)arg1;
//+ (long) updateKeyFacesOfPersons:(id)arg1 forceUpdate:(BOOL)arg2 completion:(^block)arg3;
- (unsigned long) numberOfAssets;
- (id) px_keyPhotoDate;
- (id) _px_localizedNameWithStyle:(long)arg1;
- (BOOL) isPersonModel;
- (BOOL) px_isEmpty;
- (id) px_localIdentifier;
- (id) px_localizedName;
- (id) px_longStyleLocalizedName;
- (id) px_nameComponents;
//- (void) requestFaceTileImageWithTargetSize:(struct CGSize)arg1 cropFactor:(unsigned long)arg2 style:(unsigned long)arg3 cacheResult:(BOOL)arg4 boundFaceRect:(BOOL)arg5 completionBlock:(^block)arg6;
- (BOOL) hidden;
- (BOOL) favorite;
- (void) setManualOrder:(long)arg1;
- (id) keyFace;
- (id) personLocalIdentifiers;
- (void) setKeyFace:(id)arg1;
- (void) setIsVerified:(BOOL)arg1;
- (id) anonymizedName;
- (void) pv_addMergeCandidatePersons:(id)arg1;
- (id) displayName;
- (long) type;
- (long) faceCount;
- (id) suggestedContacts;
- (id) objectReference;
- (id) name;
- (id) description;
- (BOOL) isVerified;
- (unsigned short) questionType;
- (id) contactMatchingDictionary;
- (unsigned short) ageType;
- (id) inferredContact;
- (unsigned short) sexType;
- (id) _createPropertyObjectOfClass:(Class)arg1;
- (id) _createPropertyObjectOfClass:(Class)arg1 preFetchedProperties:(id)arg2;
- (Class) changeRequestClass;
- (short) detectionType;
- (void) fetchPropertySetsIfNeeded;
- (unsigned short) genderType;
- (id) initWithFetchDictionary:(id)arg1 propertyHint:(unsigned long)arg2 photoLibrary:(id)arg3;
- (BOOL) isInPersonNamingModel;
- (id) linkedContactWithKeysToFetch:(id)arg1;
- (unsigned long) manualOrder;
- (void) markAsNeedingKeyFace;
- (double) mergeCandidateConfidence;
- (unsigned long) persistedSuggestionForClient;
- (id) personUri;
- (id) userFeedbackProperties;
- (long) verifiedType;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
