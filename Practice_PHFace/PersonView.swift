//
//  PersonView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/10/23.
//

import SwiftUI
import PhotosUI

extension PHAsset: Identifiable {
    public var id: Int { hashValue }
}

struct PersonView: View {
    private let phPerson: PHPerson
    private let phAssets: [PHAsset]
    @State private var selectedPHAsset: PHAsset?
    
    init(phPerson: PHPerson) {
        let fetchResult: PHFetchResult<PHAsset> = PHAsset.fetchAssets(forPerson: phPerson, options: nil) as! PHFetchResult<PHAsset>
        
        var phAssets: [PHAsset] = .init()
        fetchResult.enumerateObjects { phAsset, _, _ in
            phAssets.append(phAsset)
        }
        
        self.phPerson = phPerson
        self.phAssets = phAssets
    }
    
    var body: some View {
        List(phAssets, id: \.self, selection: $selectedPHAsset) { phAsset in
            Text(phAsset.localIdentifier)
        }
        .sheet(item: $selectedPHAsset) { newValue in
            NavigationStack { 
                AssetView(phAsset: newValue)
            }
        }
    }
}

#Preview {
    PersonView(phPerson: .init())
}
